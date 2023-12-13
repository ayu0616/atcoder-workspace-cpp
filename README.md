# atcoder-workspace-cpp

提出コードは`a*c000/X/main.cpp`に記述

`lib.hpp`を貼り付けた`main-combined.cpp`を作成し、それを提出している。

## 重要

誤って公開してはいけないコードをコミットしないようにコミット前に確認する処理を実行する。

処理は`.githooks/pre-commit`に記述している。

コミット時に自動実行する方法

```sh
git config --local core.hooksPath .githooks
```

## scripts 内のスクリプトについて

便利なコマンドをまとめている。

### 使用方法

vscode の設定ファイルに以下を追加する（OS によって異なる）。

```json
"terminal.integrated.env.osx": {
    "PATH": "${env:PATH}:${workspaceFolder}/scripts"
}
```

こうすることで、vscode のターミナルでスクリプトを実行できるようになる。
