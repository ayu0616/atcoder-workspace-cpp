import datetime
import os
import subprocess
import sys
from glob import glob
from threading import Thread
from time import sleep

import dotenv
import requests
from bs4 import BeautifulSoup

contest = sys.argv[1]

is_wait = input("Wait for the contest to start? (y/N) ").strip()


def main():
    check_duplicate()
    threads = [Thread(target=gen)]
    if check_is_wait(is_wait):
        threads.append(Thread(target=open_browser))
        wait()

    for t in threads:
        t.start()
    for t in threads:
        t.join()

    # download_pdf()


def check_is_wait(c: str):
    """待機するかどうかのオプションで、yかYが入力されたら待機する

    Parameters
    ----------
    c: str -> 入力された文字列
    """
    return c == "y" or c == "Y"


def check_duplicate():
    """コンテストの重複があれば終了する"""
    if os.path.exists(contest):
        print(f"Directory {contest} already exists.")
        sys.exit(1)


def open_browser():
    """ブラウザでコンテストのページを開く"""
    sleep(2)
    subprocess.run(f"open https://atcoder.jp/contests/{contest}/tasks/{contest}_a", shell=True)


def gen():
    """コンテストのディレクトリを作成し、atcoder-toolsでコードを生成する"""
    subprocess.run(f"atcoder-tools gen {contest} --config=.atcodertools.toml", shell=True)
    search_fname = os.path.join(contest, "**/*.cpp")
    cpp_files = glob(search_fname)
    cpp_files.sort()
    subprocess.run(f"code-insiders {' '.join(cpp_files)}", shell=True)
    subprocess.run(f"chmod 777 {' '.join(cpp_files)}", shell=True)


def wait():
    """コンテスト開始まで待機する"""
    now = datetime.datetime.now()
    start_time = datetime.datetime(now.year, now.month, now.day, now.hour + 1, 0, 0)
    waiting_time = int((start_time - now).total_seconds())
    while waiting_time > 0:
        now = datetime.datetime.now()
        waiting_time = int((start_time - now).total_seconds())
        print(f"\rWaiting for {waiting_time} seconds...", end="")
        sleep(0.5)
    print()


def download_pdf():
    """問題文のPDFをダウンロードする"""
    dotenv.load_dotenv()
    username = os.getenv("ATCODER_USERNAME")
    password = os.getenv("ATCODER_PASSWORD")

    session = requests.Session()
    soup = BeautifulSoup(session.get("https://atcoder.jp/login").text, "html.parser")
    token = soup.find_all("form")[1].find("input", type="hidden").get("value")
    session.post("https://atcoder.jp/login", data={"username": username, "password": password, "csrf_token": token})
    res = session.get(f"https://img.atcoder.jp/{contest}/tasks.pdf")
    with open(f"{contest}/tasks.pdf", "wb") as f:
        f.write(res.content)


if __name__ == "__main__":
    main()
