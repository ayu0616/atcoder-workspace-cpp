	.arch armv8-a
	.text
	.align	2
	.p2align 4,,11
	.globl __ZNKSt5ctypeIcE8do_widenEc
	.weak_definition __ZNKSt5ctypeIcE8do_widenEc
__ZNKSt5ctypeIcE8do_widenEc:
LFB2175:
	mov	w0, w1
	ret
LFE2175:
	.cstring
	.align	3
lC0:
	.ascii "cannot create std::vector larger than max_size()\0"
	.text
	.align	2
	.p2align 4,,11
__ZNSt6vectorIiSaIiEEC1EmRKiRKS0_.isra.0:
LFB12339:
	stp	x29, x30, [sp, -48]!
LCFI0:
	mov	x29, sp
	stp	x19, x20, [sp, 16]
LCFI1:
	mov	x20, x0
	mov	x0, 2305843009213693951
	cmp	x1, x0
	bhi	L10
	stp	xzr, xzr, [x20]
	str	xzr, [x20, 16]
	cbz	x1, L11
	str	x21, [sp, 32]
LCFI2:
	mov	x21, x2
	lsl	x19, x1, 2
	mov	x0, x19
	bl	__Znwm
	ldr	w2, [x21]
	add	x1, x0, x19
	str	x0, [x20]
	str	x1, [x20, 16]
	.p2align 3,,7
L7:
	str	w2, [x0], 4
	cmp	x0, x1
	bne	L7
	ldr	x21, [sp, 32]
LCFI3:
L6:
	str	x1, [x20, 8]
	ldp	x19, x20, [sp, 16]
	ldp	x29, x30, [sp], 48
LCFI4:
	ret
L11:
LCFI5:
	str	xzr, [x20]
	b	L6
L10:
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
	str	x21, [sp, 32]
LCFI6:
	bl	__ZSt20__throw_length_errorPKc
LFE12339:
	.align	2
	.p2align 4,,11
__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE.isra.0:
LFB12342:
	cbz	x0, L73
	stp	x29, x30, [sp, -96]!
LCFI7:
	mov	x29, sp
	stp	x23, x24, [sp, 48]
LCFI8:
	mov	x23, x0
	stp	x19, x20, [sp, 16]
LCFI9:
L30:
	ldr	x24, [x23, 24]
	cbz	x24, L14
	stp	x25, x26, [sp, 64]
LCFI10:
L29:
	ldr	x25, [x24, 24]
	cbz	x25, L15
L28:
	ldr	x26, [x25, 24]
	cbz	x26, L16
L27:
	ldr	x19, [x26, 24]
	cbz	x19, L17
L26:
	ldr	x20, [x19, 24]
	cbz	x20, L18
	stp	x21, x22, [sp, 32]
LCFI11:
	str	x27, [sp, 80]
LCFI12:
L25:
	ldr	x27, [x20, 24]
	cbz	x27, L19
L24:
	ldr	x21, [x27, 24]
	cbz	x21, L20
L23:
	ldr	x22, [x21, 24]
	cbz	x22, L21
L22:
	ldr	x0, [x22, 24]
	bl	__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE.isra.0
	mov	x0, x22
	mov	x1, 40
	ldr	x22, [x22, 16]
	bl	__ZdlPvm
	cbnz	x22, L22
L21:
	ldr	x22, [x21, 16]
	mov	x0, x21
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x22, L20
	mov	x21, x22
	b	L23
L74:
	ldp	x21, x22, [sp, 32]
LCFI13:
	ldr	x27, [sp, 80]
LCFI14:
L18:
	mov	x0, x19
	ldr	x20, [x19, 16]
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x20, L17
	mov	x19, x20
	b	L26
	.p2align 2,,3
L19:
LCFI15:
	ldr	x21, [x20, 16]
	mov	x0, x20
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x21, L74
	mov	x20, x21
	b	L25
L17:
LCFI16:
	ldr	x19, [x26, 16]
	mov	x0, x26
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x19, L16
	mov	x26, x19
	b	L27
	.p2align 2,,3
L20:
LCFI17:
	ldr	x21, [x27, 16]
	mov	x0, x27
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x21, L19
	mov	x27, x21
	b	L24
L16:
LCFI18:
	ldr	x19, [x25, 16]
	mov	x0, x25
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x19, L15
	mov	x25, x19
	b	L28
L15:
	ldr	x19, [x24, 16]
	mov	x0, x24
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x19, L75
	mov	x24, x19
	b	L29
L75:
	ldp	x25, x26, [sp, 64]
LCFI19:
L14:
	mov	x0, x23
	ldr	x19, [x23, 16]
	mov	x1, 40
	bl	__ZdlPvm
	cbz	x19, L76
	mov	x23, x19
	b	L30
L76:
	ldp	x19, x20, [sp, 16]
	ldp	x23, x24, [sp, 48]
	ldp	x29, x30, [sp], 96
LCFI20:
	ret
L73:
	ret
LFE12342:
	.align	2
	.p2align 4,,11
	.globl __Z8is_primex
__Z8is_primex:
LFB9824:
	cmp	x0, 1
	ble	L84
	cmp	x0, 3
	ble	L82
	tbz	x0, 0, L84
	mov	x1, 2
	b	L79
	.p2align 2,,3
L80:
	sdiv	x2, x0, x1
	msub	x2, x2, x1, x0
	cbz	x2, L84
L79:
	add	x1, x1, 1
	mul	x2, x1, x1
	cmp	x2, x0
	ble	L80
L82:
	mov	w0, 1
	ret
	.p2align 2,,3
L84:
	mov	w0, 0
	ret
LFE9824:
	.align	2
	.p2align 4,,11
	.globl __ZNSt6vectorISt3setIiSt4lessIiESaIiEESaIS4_EED1Ev
	.weak_definition __ZNSt6vectorISt3setIiSt4lessIiESaIiEESaIS4_EED1Ev
__ZNSt6vectorISt3setIiSt4lessIiESaIiEESaIS4_EED1Ev:
LFB10655:
	stp	x29, x30, [sp, -48]!
LCFI21:
	mov	x29, sp
	stp	x19, x20, [sp, 16]
	stp	x21, x22, [sp, 32]
LCFI22:
	mov	x22, x0
	ldp	x20, x21, [x0]
	cmp	x20, x21
	beq	L86
	.p2align 3,,7
L88:
	ldr	x19, [x20, 16]
	cbz	x19, L90
L87:
	ldr	x0, [x19, 24]
	bl	__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE.isra.0
	mov	x0, x19
	mov	x1, 40
	ldr	x19, [x19, 16]
	bl	__ZdlPvm
	cbnz	x19, L87
L90:
	add	x20, x20, 48
	cmp	x21, x20
	bne	L88
	ldr	x21, [x22]
L86:
	cbz	x21, L85
	ldr	x1, [x22, 16]
	mov	x0, x21
	ldp	x19, x20, [sp, 16]
	sub	x1, x1, x21
	ldp	x21, x22, [sp, 32]
	ldp	x29, x30, [sp], 48
LCFI23:
	b	__ZdlPvm
	.p2align 2,,3
L85:
LCFI24:
	ldp	x19, x20, [sp, 16]
	ldp	x21, x22, [sp, 32]
	ldp	x29, x30, [sp], 48
LCFI25:
	ret
LFE10655:
	.align	2
	.p2align 4,,11
	.globl __ZNSt11_Deque_baseIiSaIiEED2Ev
	.weak_definition __ZNSt11_Deque_baseIiSaIiEED2Ev
__ZNSt11_Deque_baseIiSaIiEED2Ev:
LFB10699:
	stp	x29, x30, [sp, -48]!
LCFI26:
	mov	x29, sp
	str	x21, [sp, 32]
LCFI27:
	mov	x21, x0
	ldr	x0, [x0]
	cbz	x0, L97
	stp	x19, x20, [sp, 16]
LCFI28:
	ldr	x20, [x21, 72]
	ldr	x19, [x21, 40]
	add	x20, x20, 8
	cmp	x19, x20
	bcs	L99
	.p2align 3,,7
L100:
	ldr	x0, [x19], 8
	mov	x1, 512
	bl	__ZdlPvm
	cmp	x20, x19
	bhi	L100
	ldr	x0, [x21]
L99:
	ldr	x1, [x21, 8]
	ldp	x19, x20, [sp, 16]
LCFI29:
	ldr	x21, [sp, 32]
	lsl	x1, x1, 3
	ldp	x29, x30, [sp], 48
LCFI30:
	b	__ZdlPvm
	.p2align 2,,3
L97:
LCFI31:
	ldr	x21, [sp, 32]
	ldp	x29, x30, [sp], 48
LCFI32:
	ret
LFE10699:
	.cstring
	.align	3
lC1:
	.ascii "vector::_M_realloc_insert\0"
	.text
	.align	2
	.p2align 4,,11
	.globl __ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
	.weak_definition __ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
__ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_:
LFB11176:
	stp	x29, x30, [sp, -96]!
LCFI33:
	mov	x29, sp
	stp	x21, x22, [sp, 32]
	stp	x23, x24, [sp, 48]
LCFI34:
	ldp	x24, x21, [x0]
	stp	x19, x20, [sp, 16]
	stp	x25, x26, [sp, 64]
LCFI35:
	mov	x25, x1
	mov	x1, 1152921504606846975
	str	x27, [sp, 80]
LCFI36:
	sub	x3, x21, x24
	asr	x3, x3, 3
	cmp	x3, x1
	beq	L125
	cmp	x24, x21
	mov	x20, x0
	csinc	x0, x3, xzr, ne
	mov	x22, x2
	sub	x26, x25, x24
	adds	x3, x3, x0
	bcs	L118
	cbnz	x3, L126
	mov	x19, 0
	mov	x23, 0
L109:
	ldr	x0, [x22]
	add	x22, x26, 8
	sub	x21, x21, x25
	add	x22, x23, x22
	str	x0, [x23, x26]
	add	x27, x22, x21
	cmp	x26, 0
	bgt	L127
	cmp	x21, 0
	bgt	L114
	cbnz	x24, L112
L115:
	ldp	x21, x22, [sp, 32]
	ldp	x25, x26, [sp, 64]
	stp	x23, x27, [x20]
	str	x19, [x20, 16]
	ldp	x19, x20, [sp, 16]
	ldp	x23, x24, [sp, 48]
	ldr	x27, [sp, 80]
	ldp	x29, x30, [sp], 96
LCFI37:
	ret
	.p2align 2,,3
L127:
LCFI38:
	mov	x2, x26
	mov	x1, x24
	mov	x0, x23
	bl	_memmove
	cmp	x21, 0
	bgt	L128
L112:
	ldr	x1, [x20, 16]
	mov	x0, x24
	sub	x1, x1, x24
	bl	__ZdlPvm
	b	L115
	.p2align 2,,3
L114:
	mov	x2, x21
	mov	x1, x25
	mov	x0, x22
	bl	_memcpy
	cbz	x24, L115
	b	L112
	.p2align 2,,3
L118:
	mov	x19, 9223372036854775800
L108:
	mov	x0, x19
	bl	__Znwm
	mov	x23, x0
	add	x19, x0, x19
	b	L109
	.p2align 2,,3
L128:
	mov	x1, x25
	mov	x2, x21
	mov	x0, x22
	bl	_memcpy
	ldr	x1, [x20, 16]
	mov	x0, x24
	sub	x1, x1, x24
	bl	__ZdlPvm
	b	L115
	.p2align 2,,3
L126:
	cmp	x3, x1
	csel	x3, x3, x1, ls
	lsl	x19, x3, 3
	b	L108
L125:
	adrp	x0, lC1@PAGE
	add	x0, x0, lC1@PAGEOFF;momd
	bl	__ZSt20__throw_length_errorPKc
LFE11176:
	.align	2
	.p2align 4,,11
	.globl __ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	.weak_definition __ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv:
LFB11212:
	stp	x29, x30, [sp, -48]!
LCFI39:
	mov	x29, sp
	stp	x19, x20, [sp, 16]
LCFI40:
	ldr	x20, [x0, 16]
	stp	x21, x22, [sp, 32]
LCFI41:
	mov	x22, x0
	cbz	x20, L130
	.p2align 3,,7
L133:
	mov	x21, x20
	ldr	x20, [x20]
	ldr	x19, [x21, 32]
	cbz	x19, L131
L132:
	ldr	x0, [x19, 24]
	bl	__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE.isra.0
	mov	x0, x19
	mov	x1, 40
	ldr	x19, [x19, 16]
	bl	__ZdlPvm
	cbnz	x19, L132
L131:
	mov	x0, x21
	mov	x1, 64
	bl	__ZdlPvm
	cbnz	x20, L133
L130:
	ldp	x0, x2, [x22]
	mov	w1, 0
	lsl	x2, x2, 3
	bl	_memset
	ldp	x19, x20, [sp, 16]
	stp	xzr, xzr, [x22, 16]
	ldp	x21, x22, [sp, 32]
	ldp	x29, x30, [sp], 48
LCFI42:
	ret
LFE11212:
	.align	2
	.p2align 4,,11
	.globl __ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEv
	.weak_definition __ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEv
__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEv:
LFB11213:
	add	x2, x0, 48
	ldp	x0, x1, [x0]
	cmp	x0, x2
	beq	L143
	lsl	x1, x1, 3
	b	__ZdlPvm
	.p2align 2,,3
L143:
	ret
LFE11213:
	.align	2
	.p2align 4,,11
	.globl __ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	.weak_definition __ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_:
LFB11214:
	stp	x29, x30, [sp, -80]!
LCFI43:
	mov	x29, sp
	stp	x19, x20, [sp, 16]
LCFI44:
	ldr	x19, [x0, 16]
	stp	x21, x22, [sp, 32]
LCFI45:
	mov	x21, x0
	stp	x23, x24, [sp, 48]
	mov	x22, x1
LCFI46:
	add	x24, x0, 8
	str	x25, [sp, 64]
LCFI47:
	cbz	x19, L146
	ldr	w20, [x1]
	mov	w6, 1
	b	L148
	.p2align 2,,3
L155:
	mov	x19, x2
L148:
	ldp	x2, x5, [x19, 16]
	ldr	w4, [x19, 32]
	cmp	w20, w4
	csel	x2, x2, x5, lt
	csel	w5, w6, wzr, lt
	cbnz	x2, L155
	mov	x23, x19
	cbnz	w5, L164
L149:
	mov	w0, 0
	cmp	w20, w4
	ble	L151
L150:
	mov	w25, 1
	cmp	x24, x23
	bne	L165
L152:
	mov	x0, 40
	bl	__Znwm
	mov	x19, x0
	ldr	w4, [x22]
	mov	w0, w25
	mov	x1, x19
	mov	x3, x24
	mov	x2, x23
	str	w4, [x19, 32]
	bl	__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	ldr	x1, [x21, 40]
	mov	w0, 1
	add	x1, x1, 1
	str	x1, [x21, 40]
L151:
	mov	x1, 0
	ldp	x21, x22, [sp, 32]
	bfi	x1, x0, 0, 8
	ldp	x23, x24, [sp, 48]
	mov	x0, x19
	ldp	x19, x20, [sp, 16]
	ldr	x25, [sp, 64]
	ldp	x29, x30, [sp], 80
LCFI48:
	ret
	.p2align 2,,3
L164:
LCFI49:
	ldr	x0, [x21, 24]
	cmp	x0, x19
	beq	L150
L153:
	mov	x0, x19
	mov	x23, x19
	bl	__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	ldr	w4, [x0, 32]
	mov	x19, x0
	b	L149
	.p2align 2,,3
L165:
	ldr	w0, [x23, 32]
	cmp	w20, w0
	cset	w25, lt
	b	L152
	.p2align 2,,3
L146:
	ldr	x0, [x0, 24]
	cmp	x0, x24
	beq	L160
	ldr	w20, [x1]
	mov	x19, x24
	b	L153
L160:
	mov	x23, x24
	mov	w25, 1
	b	L152
LFE11214:
	.align	2
	.p2align 4,,11
	.globl __ZNSt12_Vector_baseIiSaIiEED2Ev
	.weak_definition __ZNSt12_Vector_baseIiSaIiEED2Ev
__ZNSt12_Vector_baseIiSaIiEED2Ev:
LFB11243:
	mov	x2, x0
	ldr	x0, [x0]
	cbz	x0, L166
	ldr	x1, [x2, 16]
	sub	x1, x1, x0
	b	__ZdlPvm
	.p2align 2,,3
L166:
	ret
LFE11243:
	.align	2
	.p2align 4,,11
	.globl __ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv
	.weak_definition __ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv
__ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv:
LFB11488:
	stp	x29, x30, [sp, -32]!
LCFI50:
	mov	x29, sp
	str	x19, [sp, 16]
LCFI51:
	mov	x19, x0
	ldr	x0, [x0]
	cbz	x0, L168
	ldr	x1, [x19, 32]
	sub	x1, x1, x0
	bl	__ZdlPvm
	str	xzr, [x19]
	str	wzr, [x19, 8]
	str	xzr, [x19, 16]
	str	wzr, [x19, 24]
	str	xzr, [x19, 32]
L168:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 32
LCFI52:
	ret
LFE11488:
	.align	2
	.p2align 4,,11
	.globl __Z13create_primesx
__Z13create_primesx:
LFB9825:
	stp	x29, x30, [sp, -128]!
LCFI53:
	mov	x29, sp
	stp	x19, x20, [sp, 16]
LCFI54:
	adds	x19, x0, 1
	stp	x23, x24, [sp, 48]
LCFI55:
	mov	x23, x8
	stp	xzr, xzr, [x8]
	str	xzr, [x8, 16]
	stp	xzr, xzr, [sp, 88]
	stp	xzr, xzr, [sp, 104]
	str	xzr, [sp, 120]
	bne	L208
L174:
	ldp	x19, x20, [sp, 16]
	mov	x0, x23
	ldp	x23, x24, [sp, 48]
	ldp	x29, x30, [sp], 128
LCFI56:
	ret
	.p2align 2,,3
L208:
LCFI57:
	stp	x21, x22, [sp, 32]
LCFI58:
	add	x21, x0, 64
	mov	x20, x0
	lsr	x21, x21, 6
	lsl	x21, x21, 3
	mov	x0, x21
LEHB0:
	bl	__Znwm
LEHE0:
	cmp	x19, 0
	add	x1, x19, 63
	csel	x4, x1, x19, lt
	negs	x3, x19
	mov	x5, x0
	add	x0, x0, x21
	asr	x4, x4, 6
	str	x5, [sp, 88]
	str	wzr, [sp, 96]
	and	x3, x3, 63
	str	x0, [sp, 120]
	and	x19, x19, 63
	add	x4, x5, x4, lsl 3
	csneg	x3, x19, x3, mi
	tbnz	x3, #63, L209
L177:
	mov	x2, x21
	mov	x0, x5
	mov	w1, -1
	mov	x19, 2
	str	w3, [sp, 80]
	add	x24, sp, 72
	str	x4, [sp, 104]
	mov	x21, 4
	str	w3, [sp, 112]
	bl	_memset
	str	x19, [sp, 72]
	mov	x5, x0
	mov	x22, 1
	cmp	x20, x22
	bgt	L178
	b	L179
	.p2align 2,,3
L182:
	add	x19, x19, 1
	str	x19, [sp, 72]
	add	x21, x21, 2
	cmp	x19, x20
	bgt	L210
L178:
	asr	x2, x19, 6
	lsl	x1, x22, x19
	ldr	x0, [x5, x2, lsl 3]
	tst	x1, x0
	beq	L182
	ldp	x1, x0, [x23, 8]
	cmp	x1, x0
	beq	L183
	str	x19, [x1], 8
	str	x1, [x23, 8]
L184:
	mov	x3, x21
	cmp	x20, x21
	blt	L182
	.p2align 3,,7
L187:
	cmp	x3, 0
	add	x2, x3, 63
	csel	x2, x2, x3, lt
	negs	x1, x3
	and	x1, x1, 63
	and	x4, x3, 63
	asr	x2, x2, 6
	csneg	x1, x4, x1, mi
	add	x2, x5, x2, lsl 3
	tbz	x1, #63, L186
	add	x1, x1, 64
	sub	x2, x2, #8
L186:
	ldr	x0, [x2]
	lsl	x1, x22, x1
	add	x3, x3, x19
	bic	x1, x0, x1
	str	x1, [x2]
	cmp	x20, x3
	bge	L187
	add	x19, x19, 1
	str	x19, [sp, 72]
	add	x21, x21, 2
	cmp	x19, x20
	ble	L178
	.p2align 3,,7
L210:
	cbz	x5, L206
L179:
	ldr	x1, [sp, 120]
	mov	x0, x5
	sub	x1, x1, x5
	bl	__ZdlPvm
	ldp	x19, x20, [sp, 16]
	mov	x0, x23
	ldp	x21, x22, [sp, 32]
LCFI59:
	ldp	x23, x24, [sp, 48]
	ldp	x29, x30, [sp], 128
LCFI60:
	ret
	.p2align 2,,3
L183:
LCFI61:
	mov	x2, x24
	mov	x0, x23
LEHB1:
	bl	__ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
LEHE1:
	ldr	x5, [sp, 88]
	b	L184
	.p2align 2,,3
L209:
	add	x3, x3, 64
	sub	x4, x4, #8
	b	L177
L206:
	ldp	x21, x22, [sp, 32]
LCFI62:
	b	L174
L191:
LCFI63:
L207:
	mov	x19, x0
	add	x0, sp, 88
	bl	__ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv
	ldr	x0, [x23]
	ldr	x1, [x23, 16]
	sub	x1, x1, x0
	cbz	x0, L189
	bl	__ZdlPvm
L189:
	mov	x0, x19
LEHB2:
	bl	__Unwind_Resume
LEHE2:
L192:
	b	L207
LFE9825:
	.section __DATA,__gcc_except_tab
GCC_except_table0:
LLSDA9825:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE9825-LLSDACSB9825
LLSDACSB9825:
	.uleb128 LEHB0-LFB9825
	.uleb128 LEHE0-LEHB0
	.uleb128 L192-LFB9825
	.uleb128 0
	.uleb128 LEHB1-LFB9825
	.uleb128 LEHE1-LEHB1
	.uleb128 L191-LFB9825
	.uleb128 0
	.uleb128 LEHB2-LFB9825
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE9825:
	.text
	.align	2
	.p2align 4,,11
	.globl __ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm
	.weak_definition __ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm
__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm:
LFB11805:
	stp	x29, x30, [sp, -48]!
LCFI64:
	mov	x29, sp
	stp	x19, x20, [sp, 16]
LCFI65:
	mov	x19, x1
	stp	x21, x22, [sp, 32]
LCFI66:
	mov	x21, x0
	cmp	x1, 1
	beq	L238
	mov	x20, x2
	mov	x0, 1152921504606846975
	cmp	x1, x0
	bhi	L239
	lsl	x22, x1, 3
	mov	x0, x22
LEHB3:
	bl	__Znwm
	mov	x20, x0
	mov	x2, x22
	mov	w1, 0
	bl	_memset
	add	x8, x21, 48
L213:
	add	x7, x21, 16
	mov	x6, 0
	ldr	x4, [x21, 16]
	str	xzr, [x21, 16]
L237:
	cbz	x4, L240
L216:
	ldrsw	x5, [x4, 8]
	mov	x3, x4
	ldr	x4, [x4]
	udiv	x2, x5, x19
	msub	x2, x2, x19, x5
	ldr	x1, [x20, x2, lsl 3]
	cbz	x1, L241
	ldr	x0, [x1]
	str	x0, [x3]
	ldr	x0, [x20, x2, lsl 3]
	str	x3, [x0]
	cbnz	x4, L216
L240:
	ldp	x0, x1, [x21]
	cmp	x8, x0
	beq	L217
	lsl	x1, x1, 3
	bl	__ZdlPvm
L217:
	stp	x20, x19, [x21]
	ldp	x19, x20, [sp, 16]
	ldp	x21, x22, [sp, 32]
	ldp	x29, x30, [sp], 48
LCFI67:
	ret
	.p2align 2,,3
L241:
LCFI68:
	ldr	x0, [x21, 16]
	str	x0, [x3]
	str	x3, [x21, 16]
	str	x7, [x20, x2, lsl 3]
	ldr	x0, [x3]
	cbz	x0, L220
	str	x3, [x20, x6, lsl 3]
L220:
	mov	x6, x2
	b	L237
	.p2align 2,,3
L238:
	mov	x20, x0
	str	xzr, [x20, 48]!
	mov	x8, x20
	b	L213
	.p2align 2,,3
L239:
	mov	x0, 2305843009213693951
	cmp	x1, x0
	bls	L215
	bl	__ZSt28__throw_bad_array_new_lengthv
L215:
	bl	__ZSt17__throw_bad_allocv
LEHE3:
L226:
	bl	___cxa_begin_catch
	ldr	x0, [x20]
	str	x0, [x21, 40]
LEHB4:
	bl	___cxa_rethrow
LEHE4:
L227:
	mov	x19, x0
	bl	___cxa_end_catch
	mov	x0, x19
LEHB5:
	bl	__Unwind_Resume
LEHE5:
LFE11805:
	.section __DATA,__gcc_except_tab
GCC_except_table1:
	.align	3
LLSDA11805:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT11805-LLSDATTD11805
LLSDATTD11805:
	.byte	0x1
	.uleb128 LLSDACSE11805-LLSDACSB11805
LLSDACSB11805:
	.uleb128 LEHB3-LFB11805
	.uleb128 LEHE3-LEHB3
	.uleb128 L226-LFB11805
	.uleb128 0x1
	.uleb128 LEHB4-LFB11805
	.uleb128 LEHE4-LEHB4
	.uleb128 L227-LFB11805
	.uleb128 0
	.uleb128 LEHB5-LFB11805
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE11805:
	.byte	0x1
	.byte	0
	.align	3
	.xword	0
LLSDATT11805:
	.text
	.align	2
	.p2align 4,,11
	.globl __ZNSt8__detail9_Map_baseIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS8_ENS_10_Select1stESt8equal_toIiESt4hashIiENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	.weak_definition __ZNSt8__detail9_Map_baseIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS8_ENS_10_Select1stESt8equal_toIiESt4hashIiENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
__ZNSt8__detail9_Map_baseIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS8_ENS_10_Select1stESt8equal_toIiESt4hashIiENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_:
LFB11222:
	stp	x29, x30, [sp, -80]!
LCFI69:
	mov	x29, sp
	ldp	x2, x5, [x0]
	str	x23, [sp, 48]
LCFI70:
	mov	x23, x1
	ldr	w1, [x1]
	stp	x21, x22, [sp, 32]
LCFI71:
	sxtw	x21, w1
	stp	x19, x20, [sp, 16]
LCFI72:
	mov	x19, x0
	udiv	x0, x21, x5
	msub	x0, x0, x5, x21
	lsl	x22, x0, 3
	ldr	x6, [x2, x0, lsl 3]
	cbz	x6, L243
	ldr	x2, [x6]
	ldr	w3, [x2, 8]
	cmp	w1, w3
	beq	L244
L271:
	ldr	x4, [x2]
	cbz	x4, L243
	ldr	w3, [x4, 8]
	mov	x6, x2
	sxtw	x7, w3
	udiv	x2, x7, x5
	msub	x2, x2, x5, x7
	cmp	x0, x2
	bne	L243
	mov	x2, x4
	cmp	w1, w3
	bne	L271
L244:
	ldr	x0, [x6]
	cbz	x0, L243
	ldp	x19, x20, [sp, 16]
	add	x0, x0, 16
	ldp	x21, x22, [sp, 32]
	ldr	x23, [sp, 48]
	ldp	x29, x30, [sp], 80
LCFI73:
	ret
	.p2align 2,,3
L243:
LCFI74:
	mov	x0, 64
LEHB6:
	bl	__Znwm
LEHE6:
	mov	x20, x0
	add	x4, x0, 24
	ldr	x1, [x19, 8]
	add	x0, x19, 32
	ldr	x2, [x19, 24]
	str	xzr, [x20]
	ldr	x5, [x19, 40]
	str	wzr, [x20, 24]
	ldr	w3, [x23]
	str	w3, [x20, 8]
	str	xzr, [x20, 32]
	mov	x3, 1
	stp	x4, x4, [x4, 16]
	str	xzr, [x4, 32]
	str	x5, [sp, 72]
LEHB7:
	bl	__ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEmmm
	tst	w0, 255
	bne	L272
	ldr	x0, [x19]
	add	x2, x0, x22
	ldr	x1, [x0, x22]
	cbz	x1, L248
L273:
	ldr	x1, [x1]
	str	x1, [x20]
	ldr	x0, [x0, x22]
	str	x20, [x0]
L249:
	ldr	x1, [x19, 24]
	add	x0, x20, 16
	ldp	x21, x22, [sp, 32]
	add	x1, x1, 1
	str	x1, [x19, 24]
	ldp	x19, x20, [sp, 16]
	ldr	x23, [sp, 48]
	ldp	x29, x30, [sp], 80
LCFI75:
	ret
	.p2align 2,,3
L272:
LCFI76:
	add	x2, sp, 72
	mov	x0, x19
	bl	__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm
LEHE7:
	ldr	x0, [x19, 8]
	udiv	x22, x21, x0
	msub	x22, x22, x0, x21
	ldr	x0, [x19]
	lsl	x22, x22, 3
	add	x2, x0, x22
	ldr	x1, [x0, x22]
	cbnz	x1, L273
L248:
	ldr	x1, [x19, 16]
	str	x1, [x20]
	str	x20, [x19, 16]
	cbz	x1, L250
	ldr	x3, [x19, 8]
	ldrsw	x4, [x1, 8]
	udiv	x1, x4, x3
	msub	x1, x1, x3, x4
	str	x20, [x0, x1, lsl 3]
L250:
	add	x0, x19, 16
	str	x0, [x2]
	b	L249
L254:
	ldr	x19, [x20, 32]
	mov	x21, x0
	cbz	x19, L274
L253:
	ldr	x0, [x19, 24]
	bl	__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE.isra.0
	ldr	x22, [x19, 16]
	mov	x0, x19
	mov	x1, 40
	bl	__ZdlPvm
	mov	x19, x22
	cbnz	x19, L253
L274:
	mov	x1, 64
	mov	x0, x20
	bl	__ZdlPvm
	mov	x0, x21
LEHB8:
	bl	__Unwind_Resume
LEHE8:
LFE11222:
	.section __DATA,__gcc_except_tab
GCC_except_table2:
LLSDA11222:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE11222-LLSDACSB11222
LLSDACSB11222:
	.uleb128 LEHB6-LFB11222
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB7-LFB11222
	.uleb128 LEHE7-LEHB7
	.uleb128 L254-LFB11222
	.uleb128 0
	.uleb128 LEHB8-LFB11222
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
LLSDACSE11222:
	.text
	.align	2
	.p2align 4,,11
	.globl __ZNSt5dequeIiSaIiEE17_M_reallocate_mapEmb
	.weak_definition __ZNSt5dequeIiSaIiEE17_M_reallocate_mapEmb
__ZNSt5dequeIiSaIiEE17_M_reallocate_mapEmb:
LFB11842:
	stp	x29, x30, [sp, -64]!
LCFI77:
	mov	x29, sp
	ldr	x3, [x0, 72]
	stp	x21, x22, [sp, 32]
LCFI78:
	mov	x21, x1
	ldr	x1, [x0, 40]
	stp	x19, x20, [sp, 16]
LCFI79:
	mov	x20, x0
	sub	x22, x3, x1
	stp	x23, x24, [sp, 48]
LCFI80:
	and	w24, w2, 255
	ldr	x0, [x0, 8]
	asr	x19, x22, 3
	add	x19, x19, 1
	add	x19, x19, x21
	cmp	x0, x19, lsl 1
	bls	L276
	sub	x0, x0, x19
	cmp	w24, 0
	ldr	x19, [x20]
	lsr	x0, x0, 1
	add	x3, x3, 8
	lsl	x0, x0, 3
	sub	x2, x3, x1
	add	x21, x0, x21, lsl 3
	csel	x0, x21, x0, ne
	add	x19, x19, x0
	cmp	x1, x19
	bls	L278
	cmp	x1, x3
	beq	L280
	mov	x0, x19
	bl	_memmove
	b	L280
	.p2align 2,,3
L276:
	cmp	x0, x21
	add	x23, x0, 2
	csel	x0, x0, x21, cs
	mov	x1, 1152921504606846975
	add	x23, x23, x0
	cmp	x23, x1
	bhi	L290
	sub	x19, x23, x19
	lsl	x0, x23, 3
	bl	__Znwm
	lsr	x19, x19, 1
	cmp	w24, 0
	ldr	x3, [x20, 72]
	lsl	x19, x19, 3
	ldr	x1, [x20, 40]
	add	x21, x19, x21, lsl 3
	csel	x19, x21, x19, ne
	add	x3, x3, 8
	mov	x24, x0
	add	x19, x0, x19
	cmp	x1, x3
	beq	L284
	sub	x2, x3, x1
	mov	x0, x19
	bl	_memmove
L284:
	ldp	x0, x1, [x20]
	lsl	x1, x1, 3
	bl	__ZdlPvm
	stp	x24, x23, [x20]
L280:
	add	x2, x19, x22
	ldr	x1, [x19]
	ldp	x23, x24, [sp, 48]
	add	x3, x1, 512
	stp	x1, x3, [x20, 24]
	ldr	x0, [x19, x22]
	str	x19, [x20, 40]
	ldp	x21, x22, [sp, 32]
	str	x0, [x20, 56]
	add	x0, x0, 512
	str	x0, [x20, 64]
	str	x2, [x20, 72]
	ldp	x19, x20, [sp, 16]
	ldp	x29, x30, [sp], 64
LCFI81:
	ret
	.p2align 2,,3
L278:
LCFI82:
	cmp	x1, x3
	beq	L280
	add	x0, x22, 8
	sub	x0, x0, x2
	add	x0, x19, x0
	bl	_memmove
	b	L280
	.p2align 2,,3
L290:
	mov	x0, 2305843009213693951
	cmp	x23, x0
	bls	L282
	bl	__ZSt28__throw_bad_array_new_lengthv
	.p2align 2,,3
L282:
	bl	__ZSt17__throw_bad_allocv
LFE11842:
	.cstring
	.align	3
lC2:
	.ascii "cannot create std::deque larger than max_size()\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.align	2
	.p2align 4,,11
	.globl _main
_main:
LFB9866:
	adrp	x0, __ZSt3cin@GOTPAGE
	ldr	x0, [x0, __ZSt3cin@GOTPAGEOFF]
	stp	x29, x30, [sp, -368]!
LCFI83:
	mov	x29, sp
	add	x1, sp, 148
	stp	x19, x20, [sp, 16]
	stp	x21, x22, [sp, 32]
	stp	x23, x24, [sp, 48]
	stp	x25, x26, [sp, 64]
	stp	x27, x28, [sp, 80]
LCFI84:
LEHB9:
	bl	__ZNSirsERi
	add	x1, sp, 152
	bl	__ZNSirsERi
	ldr	w0, [sp, 148]
	mov	x2, -6148914691236517206
	movk	x2, 0x2aa, lsl 48
	sxtw	x1, w0
	cmp	x1, x2
	bhi	L351
	cbz	x1, L352
	mov	w1, 48
	smull	x19, w0, w1
	mov	x0, x19
	bl	__Znwm
LEHE9:
	add	x2, x0, x19
	str	x0, [sp, 104]
	str	x0, [sp, 160]
	str	x2, [sp, 176]
	.p2align 3,,7
L295:
	add	x1, x0, 8
	str	wzr, [x0, 8]
	stp	xzr, x1, [x0, 16]
	stp	x1, xzr, [x0, 32]
	add	x0, x0, 48
	cmp	x0, x2
	bne	L295
	ldr	w0, [sp, 148]
L294:
	fmov	s0, 1.0e+0
	add	x1, sp, 280
	mov	x3, 1
	str	x2, [sp, 168]
	str	wzr, [sp, 184]
	stp	x1, x3, [sp, 232]
	stp	xzr, xzr, [sp, 248]
	str	s0, [sp, 264]
	stp	xzr, xzr, [sp, 272]
	cmp	w0, 0
	ble	L353
	ldr	x21, [sp, 104]
	add	x28, sp, 208
	adrp	x23, __ZSt3cin@GOTPAGE
	ldr	x23, [x23, __ZSt3cin@GOTPAGEOFF]
	add	x22, sp, 232
	add	x20, sp, 288
	add	x24, sp, 184
	mov	w25, 0
	.p2align 3,,7
L299:
	mov	x1, x28
	mov	x0, x23
LEHB10:
	bl	__ZNSirsERi
	ldr	w0, [sp, 208]
	mov	w19, 0
	cmp	w0, 0
	ble	L302
	.p2align 3,,7
L301:
	mov	x1, x20
	mov	x0, x23
	bl	__ZNSirsERi
	mov	x1, x20
	mov	x0, x21
	bl	__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	mov	x1, x20
	mov	x0, x22
	bl	__ZNSt8__detail9_Map_baseIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS8_ENS_10_Select1stESt8equal_toIiESt4hashIiENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	mov	x1, x24
	bl	__ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	ldr	w0, [sp, 208]
	add	w19, w19, 1
	cmp	w0, w19
	bgt	L301
L302:
	ldr	w0, [sp, 148]
	add	w25, w25, 1
	str	w25, [sp, 184]
	add	x21, x21, 48
	cmp	w25, w0
	blt	L299
L300:
	ldr	w1, [sp, 152]
	mov	w3, -1
	add	x2, sp, 288
	add	x0, sp, 184
	add	w1, w1, 1
	stp	x2, x0, [sp, 128]
	sxtw	x1, w1
	str	w3, [sp, 288]
	bl	__ZNSt6vectorIiSaIiEEC1EmRKiRKS0_.isra.0
LEHE10:
	ldr	x2, [sp, 128]
	add	x28, sp, 208
	ldrsw	x1, [sp, 148]
	mov	x0, x28
	str	wzr, [sp, 288]
LEHB11:
	bl	__ZNSt6vectorIiSaIiEEC1EmRKiRKS0_.isra.0
LEHE11:
	movi	v0.4s, 0
	mov	x1, 8
	mov	x0, 64
	str	x1, [sp, 296]
	stp	q0, q0, [sp, 304]
	stp	q0, q0, [sp, 336]
LEHB12:
	bl	__Znwm
LEHE12:
	mov	x19, x0
	add	x20, x19, 24
	mov	x0, 512
	str	x19, [sp, 288]
LEHB13:
	bl	__Znwm
LEHE13:
	mov	x2, x0
	mov	w3, 1
	ldr	x23, [sp, 184]
	add	x1, x0, 512
	str	w3, [x2], 4
	add	x3, sp, 156
	str	x0, [x19, 24]
	stp	x0, x0, [sp, 304]
	stp	x1, x20, [sp, 320]
	stp	x2, x0, [sp, 336]
	stp	x1, x20, [sp, 352]
	sub	x1, x1, #4
	str	wzr, [x23, 4]
	str	x3, [sp, 120]
	ldr	w27, [x0]
	str	w27, [sp, 156]
	cmp	x0, x1
	beq	L308
L355:
	add	x2, x0, 4
L309:
	ldr	x1, [sp, 120]
	mov	x0, x22
	str	x2, [sp, 304]
LEHB14:
	bl	__ZNSt8__detail9_Map_baseIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS8_ENS_10_Select1stESt8equal_toIiESt4hashIiENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	ldr	x20, [x0, 24]
	add	x26, x0, 8
	cmp	x20, x26
	beq	L315
	ldr	x25, [sp, 208]
	add	x27, x23, w27, sxtw 2
	b	L314
	.p2align 2,,3
L316:
	mov	x0, x20
	bl	__ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	mov	x20, x0
	cmp	x26, x0
	beq	L315
L314:
	ldr	w0, [x20, 32]
	sxtw	x1, w0
	ldr	w2, [x25, x1, lsl 2]
	cbnz	w2, L316
	ldr	x3, [sp, 104]
	mov	w2, 48
	smaddl	x0, w0, w2, x3
	mov	w2, 1
	str	w2, [x25, x1, lsl 2]
	add	x24, x0, 8
	ldr	x19, [x0, 24]
	cmp	x19, x24
	bne	L321
	b	L316
	.p2align 2,,3
L317:
	mov	x0, x19
	bl	__ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	mov	x19, x0
	cmp	x24, x0
	beq	L316
L321:
	ldr	w21, [x19, 32]
	sxtw	x0, w21
	ldr	w1, [x23, x0, lsl 2]
	cmn	w1, #1
	bne	L317
	ldr	x2, [sp, 352]
	ldr	x1, [sp, 336]
	sub	x2, x2, #4
	ldr	w3, [x27]
	add	w3, w3, 1
	str	w3, [x23, x0, lsl 2]
	cmp	x1, x2
	beq	L318
	mov	x0, x1
	str	w21, [x0], 4
	str	x0, [sp, 336]
	b	L317
	.p2align 2,,3
L315:
	ldr	x0, [sp, 304]
	ldr	x1, [sp, 336]
	cmp	x1, x0
	beq	L354
	ldr	x1, [sp, 320]
	ldr	w27, [x0]
	sub	x1, x1, #4
	str	w27, [sp, 156]
	cmp	x0, x1
	bne	L355
L308:
	ldr	x0, [sp, 312]
	mov	x1, 512
	bl	__ZdlPvm
	ldr	x0, [sp, 328]
	add	x1, x0, 8
	ldr	x2, [x0, 8]
	str	x1, [sp, 328]
	add	x0, x2, 512
	stp	x2, x0, [sp, 312]
	b	L309
	.p2align 2,,3
L318:
	ldr	x2, [sp, 328]
	ldr	x3, [sp, 360]
	str	x3, [sp, 112]
	ldr	x0, [sp, 344]
	sub	x2, x3, x2
	ldr	x4, [sp, 304]
	cmp	x3, 0
	ldr	x3, [sp, 320]
	asr	x2, x2, 3
	sub	x0, x1, x0
	cset	x5, ne
	sub	x1, x2, x5
	sub	x2, x3, x4
	asr	x0, x0, 2
	add	x0, x0, x1, lsl 7
	mov	x1, 2305843009213693951
	add	x0, x0, x2, asr 2
	cmp	x0, x1
	beq	L356
	ldp	x0, x1, [sp, 288]
	ldr	x2, [sp, 112]
	sub	x0, x2, x0
	sub	x0, x1, x0, asr 3
	cmp	x0, 1
	bls	L357
L320:
	mov	x0, 512
	bl	__Znwm
	ldr	x1, [sp, 112]
	add	x2, x0, 512
	str	x0, [x1, 8]!
	ldr	x3, [sp, 336]
	str	w21, [x3]
	stp	x0, x0, [sp, 336]
	stp	x2, x1, [sp, 352]
	b	L317
L357:
	ldr	x0, [sp, 128]
	mov	w2, 0
	mov	x1, 1
	bl	__ZNSt5dequeIiSaIiEE17_M_reallocate_mapEmb
	ldr	x0, [sp, 360]
	str	x0, [sp, 112]
	b	L320
L352:
	mov	x2, 0
	str	xzr, [sp, 104]
	str	xzr, [sp, 160]
	str	xzr, [sp, 176]
	b	L294
L354:
	ldrsw	x1, [sp, 152]
	lsl	x2, x1, 2
	ldr	w0, [x23, x2]
	cmn	w0, #1
	beq	L322
	sub	w0, w0, #1
	str	w0, [x23, x2]
	ldrsw	x1, [sp, 152]
L322:
	ldr	w1, [x23, x1, lsl 2]
	adrp	x0, __ZSt4cout@GOTPAGE
	ldr	x0, [x0, __ZSt4cout@GOTPAGEOFF]
	bl	__ZNSolsEi
	mov	x19, x0
	ldr	x0, [x0]
	ldr	x0, [x0, -24]
	add	x0, x19, x0
	ldr	x20, [x0, 240]
	cbz	x20, L358
	ldrsb	w0, [x20, 56]
	cbz	w0, L324
	ldrsb	w1, [x20, 67]
L325:
	mov	x0, x19
	bl	__ZNSo3putEc
	bl	__ZNSo5flushEv
	ldr	x0, [sp, 128]
	bl	__ZNSt11_Deque_baseIiSaIiEED2Ev
	mov	x0, x28
	bl	__ZNSt12_Vector_baseIiSaIiEED2Ev
	ldr	x0, [sp, 136]
	bl	__ZNSt12_Vector_baseIiSaIiEED2Ev
	mov	x0, x22
	bl	__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	mov	x0, x22
	bl	__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEv
	add	x0, sp, 160
	bl	__ZNSt6vectorISt3setIiSt4lessIiESaIiEESaIS4_EED1Ev
	ldp	x19, x20, [sp, 16]
	mov	w0, 0
	ldp	x21, x22, [sp, 32]
	ldp	x23, x24, [sp, 48]
	ldp	x25, x26, [sp, 64]
	ldp	x27, x28, [sp, 80]
	ldp	x29, x30, [sp], 368
LCFI85:
	ret
L324:
LCFI86:
	mov	x0, x20
	bl	__ZNKSt5ctypeIcE13_M_widen_initEv
	ldr	x1, [x20]
	adrp	x0, __ZNKSt5ctypeIcE8do_widenEc@GOTPAGE
	ldr	x0, [x0, __ZNKSt5ctypeIcE8do_widenEc@GOTPAGEOFF]
	ldr	x2, [x1, 48]
	cmp	x2, x0
	bne	L359
	mov	w1, 10
	b	L325
L353:
	add	x22, sp, 232
	b	L300
L359:
	mov	x0, x20
	mov	w1, 10
	blr	x2
	sxtb	w1, w0
	b	L325
L356:
	adrp	x0, lC2@PAGE
	add	x0, x0, lC2@PAGEOFF;momd
	bl	__ZSt20__throw_length_errorPKc
LEHE14:
L351:
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
LEHB15:
	bl	__ZSt20__throw_length_errorPKc
LEHE15:
L358:
LEHB16:
	bl	__ZSt16__throw_bad_castv
LEHE16:
L331:
	mov	x19, x0
L327:
	ldr	x0, [sp, 136]
	bl	__ZNSt12_Vector_baseIiSaIiEED2Ev
L328:
	mov	x0, x22
	bl	__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	mov	x0, x22
	bl	__ZNSt10_HashtableIiSt4pairIKiSt3setIiSt4lessIiESaIiEEESaIS7_ENSt8__detail10_Select1stESt8equal_toIiESt4hashIiENS9_18_Mod_range_hashingENS9_20_Default_ranged_hashENS9_20_Prime_rehash_policyENS9_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEv
	add	x0, sp, 160
	bl	__ZNSt6vectorISt3setIiSt4lessIiESaIiEESaIS4_EED1Ev
	mov	x0, x19
LEHB17:
	bl	__Unwind_Resume
LEHE17:
L330:
	mov	x19, x0
	b	L328
L333:
	mov	x19, x0
	ldr	x0, [sp, 128]
	bl	__ZNSt11_Deque_baseIiSaIiEED2Ev
	mov	x1, x19
L307:
	mov	x0, x28
	mov	x19, x1
	bl	__ZNSt12_Vector_baseIiSaIiEED2Ev
	b	L327
L335:
	bl	___cxa_begin_catch
LEHB18:
	bl	___cxa_rethrow
LEHE18:
L332:
	mov	x1, x0
	b	L307
L336:
	mov	x20, x0
	bl	___cxa_end_catch
	mov	x0, x20
	bl	___cxa_begin_catch
	mov	x0, x19
	mov	x1, 64
	bl	__ZdlPvm
LEHB19:
	bl	___cxa_rethrow
LEHE19:
L334:
	mov	x19, x0
	bl	___cxa_end_catch
	mov	x1, x19
	b	L307
LFE9866:
	.section __DATA,__gcc_except_tab
GCC_except_table3:
	.align	3
LLSDA9866:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT9866-LLSDATTD9866
LLSDATTD9866:
	.byte	0x1
	.uleb128 LLSDACSE9866-LLSDACSB9866
LLSDACSB9866:
	.uleb128 LEHB9-LFB9866
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB10-LFB9866
	.uleb128 LEHE10-LEHB10
	.uleb128 L330-LFB9866
	.uleb128 0
	.uleb128 LEHB11-LFB9866
	.uleb128 LEHE11-LEHB11
	.uleb128 L331-LFB9866
	.uleb128 0
	.uleb128 LEHB12-LFB9866
	.uleb128 LEHE12-LEHB12
	.uleb128 L332-LFB9866
	.uleb128 0
	.uleb128 LEHB13-LFB9866
	.uleb128 LEHE13-LEHB13
	.uleb128 L335-LFB9866
	.uleb128 0x1
	.uleb128 LEHB14-LFB9866
	.uleb128 LEHE14-LEHB14
	.uleb128 L333-LFB9866
	.uleb128 0
	.uleb128 LEHB15-LFB9866
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB16-LFB9866
	.uleb128 LEHE16-LEHB16
	.uleb128 L333-LFB9866
	.uleb128 0
	.uleb128 LEHB17-LFB9866
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB18-LFB9866
	.uleb128 LEHE18-LEHB18
	.uleb128 L336-LFB9866
	.uleb128 0x1
	.uleb128 LEHB19-LFB9866
	.uleb128 LEHE19-LEHB19
	.uleb128 L334-LFB9866
	.uleb128 0
LLSDACSE9866:
	.byte	0x1
	.byte	0
	.align	3
	.xword	0
LLSDATT9866:
	.section __TEXT,__text_startup,regular,pure_instructions
	.align	2
	.p2align 4,,11
__GLOBAL__sub_I_main.cpp:
LFB12329:
	stp	x29, x30, [sp, -32]!
LCFI87:
	mov	x29, sp
	str	x19, [sp, 16]
LCFI88:
	adrp	x19, __ZStL8__ioinit@PAGE
	add	x19, x19, __ZStL8__ioinit@PAGEOFF;momd
	mov	x0, x19
	bl	__ZNSt8ios_base4InitC1Ev
	mov	x1, x19
	adrp	x2, ___dso_handle@PAGE
	ldr	x19, [sp, 16]
	add	x2, x2, ___dso_handle@PAGEOFF;momd
	ldp	x29, x30, [sp], 32
LCFI89:
	adrp	x0, __ZNSt8ios_base4InitD1Ev@GOTPAGE
	ldr	x0, [x0, __ZNSt8ios_base4InitD1Ev@GOTPAGEOFF]
	b	___cxa_atexit
LFE12329:
	.zerofill __DATA,__bss,__ZStL8__ioinit,1,0
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zPLR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x1e
	.uleb128 0x7
	.byte	0x9b
	.long	___gxx_personality_v0@GOT-.
	.byte	0x10
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB2175-.
	.set L$set$2,LFE2175-LFB2175
	.quad L$set$2
	.uleb128 0x8
	.quad	0
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB12339-.
	.set L$set$4,LFE12339-LFB12339
	.quad L$set$4
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB12339
	.long L$set$5
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0x93
	.uleb128 0x4
	.byte	0x94
	.uleb128 0x3
	.byte	0x4
	.set L$set$7,LCFI2-LCFI1
	.long L$set$7
	.byte	0x95
	.uleb128 0x2
	.byte	0x4
	.set L$set$8,LCFI3-LCFI2
	.long L$set$8
	.byte	0xd5
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xb
	.byte	0x4
	.set L$set$11,LCFI6-LCFI5
	.long L$set$11
	.byte	0x95
	.uleb128 0x2
	.align	3
LEFDE3:
LSFDE5:
	.set L$set$12,LEFDE5-LASFDE5
	.long L$set$12
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB12342-.
	.set L$set$13,LFE12342-LFB12342
	.quad L$set$13
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$14,LCFI7-LFB12342
	.long L$set$14
	.byte	0xe
	.uleb128 0x60
	.byte	0x9d
	.uleb128 0xc
	.byte	0x9e
	.uleb128 0xb
	.byte	0x4
	.set L$set$15,LCFI8-LCFI7
	.long L$set$15
	.byte	0x97
	.uleb128 0x6
	.byte	0x98
	.uleb128 0x5
	.byte	0x4
	.set L$set$16,LCFI9-LCFI8
	.long L$set$16
	.byte	0x93
	.uleb128 0xa
	.byte	0x94
	.uleb128 0x9
	.byte	0x4
	.set L$set$17,LCFI10-LCFI9
	.long L$set$17
	.byte	0x9a
	.uleb128 0x3
	.byte	0x99
	.uleb128 0x4
	.byte	0x4
	.set L$set$18,LCFI11-LCFI10
	.long L$set$18
	.byte	0x96
	.uleb128 0x7
	.byte	0x95
	.uleb128 0x8
	.byte	0x4
	.set L$set$19,LCFI12-LCFI11
	.long L$set$19
	.byte	0x9b
	.uleb128 0x2
	.byte	0x4
	.set L$set$20,LCFI13-LCFI12
	.long L$set$20
	.byte	0xd6
	.byte	0xd5
	.byte	0x4
	.set L$set$21,LCFI14-LCFI13
	.long L$set$21
	.byte	0xdb
	.byte	0x4
	.set L$set$22,LCFI15-LCFI14
	.long L$set$22
	.byte	0x95
	.uleb128 0x8
	.byte	0x96
	.uleb128 0x7
	.byte	0x9b
	.uleb128 0x2
	.byte	0x4
	.set L$set$23,LCFI16-LCFI15
	.long L$set$23
	.byte	0xd5
	.byte	0xd6
	.byte	0xdb
	.byte	0x4
	.set L$set$24,LCFI17-LCFI16
	.long L$set$24
	.byte	0x95
	.uleb128 0x8
	.byte	0x96
	.uleb128 0x7
	.byte	0x9b
	.uleb128 0x2
	.byte	0x4
	.set L$set$25,LCFI18-LCFI17
	.long L$set$25
	.byte	0xd5
	.byte	0xd6
	.byte	0xdb
	.byte	0x4
	.set L$set$26,LCFI19-LCFI18
	.long L$set$26
	.byte	0xda
	.byte	0xd9
	.byte	0x4
	.set L$set$27,LCFI20-LCFI19
	.long L$set$27
	.byte	0xde
	.byte	0xdd
	.byte	0xd7
	.byte	0xd8
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE5:
LSFDE7:
	.set L$set$28,LEFDE7-LASFDE7
	.long L$set$28
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB9824-.
	.set L$set$29,LFE9824-LFB9824
	.quad L$set$29
	.uleb128 0x8
	.quad	0
	.align	3
LEFDE7:
LSFDE9:
	.set L$set$30,LEFDE9-LASFDE9
	.long L$set$30
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB10655-.
	.set L$set$31,LFE10655-LFB10655
	.quad L$set$31
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$32,LCFI21-LFB10655
	.long L$set$32
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$33,LCFI22-LCFI21
	.long L$set$33
	.byte	0x93
	.uleb128 0x4
	.byte	0x94
	.uleb128 0x3
	.byte	0x95
	.uleb128 0x2
	.byte	0x96
	.uleb128 0x1
	.byte	0x4
	.set L$set$34,LCFI23-LCFI22
	.long L$set$34
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$35,LCFI24-LCFI23
	.long L$set$35
	.byte	0xb
	.byte	0x4
	.set L$set$36,LCFI25-LCFI24
	.long L$set$36
	.byte	0xde
	.byte	0xdd
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE9:
LSFDE11:
	.set L$set$37,LEFDE11-LASFDE11
	.long L$set$37
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB10699-.
	.set L$set$38,LFE10699-LFB10699
	.quad L$set$38
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$39,LCFI26-LFB10699
	.long L$set$39
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$40,LCFI27-LCFI26
	.long L$set$40
	.byte	0x95
	.uleb128 0x2
	.byte	0x4
	.set L$set$41,LCFI28-LCFI27
	.long L$set$41
	.byte	0x94
	.uleb128 0x3
	.byte	0x93
	.uleb128 0x4
	.byte	0x4
	.set L$set$42,LCFI29-LCFI28
	.long L$set$42
	.byte	0xd4
	.byte	0xd3
	.byte	0x4
	.set L$set$43,LCFI30-LCFI29
	.long L$set$43
	.byte	0xde
	.byte	0xdd
	.byte	0xd5
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$44,LCFI31-LCFI30
	.long L$set$44
	.byte	0xe
	.uleb128 0x30
	.byte	0x95
	.uleb128 0x2
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$45,LCFI32-LCFI31
	.long L$set$45
	.byte	0xde
	.byte	0xdd
	.byte	0xd5
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE11:
LSFDE13:
	.set L$set$46,LEFDE13-LASFDE13
	.long L$set$46
LASFDE13:
	.long	LASFDE13-EH_frame1
	.quad	LFB11176-.
	.set L$set$47,LFE11176-LFB11176
	.quad L$set$47
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$48,LCFI33-LFB11176
	.long L$set$48
	.byte	0xe
	.uleb128 0x60
	.byte	0x9d
	.uleb128 0xc
	.byte	0x9e
	.uleb128 0xb
	.byte	0x4
	.set L$set$49,LCFI34-LCFI33
	.long L$set$49
	.byte	0x95
	.uleb128 0x8
	.byte	0x96
	.uleb128 0x7
	.byte	0x97
	.uleb128 0x6
	.byte	0x98
	.uleb128 0x5
	.byte	0x4
	.set L$set$50,LCFI35-LCFI34
	.long L$set$50
	.byte	0x93
	.uleb128 0xa
	.byte	0x94
	.uleb128 0x9
	.byte	0x99
	.uleb128 0x4
	.byte	0x9a
	.uleb128 0x3
	.byte	0x4
	.set L$set$51,LCFI36-LCFI35
	.long L$set$51
	.byte	0x9b
	.uleb128 0x2
	.byte	0x4
	.set L$set$52,LCFI37-LCFI36
	.long L$set$52
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xdb
	.byte	0xd9
	.byte	0xda
	.byte	0xd7
	.byte	0xd8
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$53,LCFI38-LCFI37
	.long L$set$53
	.byte	0xb
	.align	3
LEFDE13:
LSFDE15:
	.set L$set$54,LEFDE15-LASFDE15
	.long L$set$54
LASFDE15:
	.long	LASFDE15-EH_frame1
	.quad	LFB11212-.
	.set L$set$55,LFE11212-LFB11212
	.quad L$set$55
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$56,LCFI39-LFB11212
	.long L$set$56
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$57,LCFI40-LCFI39
	.long L$set$57
	.byte	0x93
	.uleb128 0x4
	.byte	0x94
	.uleb128 0x3
	.byte	0x4
	.set L$set$58,LCFI41-LCFI40
	.long L$set$58
	.byte	0x95
	.uleb128 0x2
	.byte	0x96
	.uleb128 0x1
	.byte	0x4
	.set L$set$59,LCFI42-LCFI41
	.long L$set$59
	.byte	0xde
	.byte	0xdd
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE15:
LSFDE17:
	.set L$set$60,LEFDE17-LASFDE17
	.long L$set$60
LASFDE17:
	.long	LASFDE17-EH_frame1
	.quad	LFB11213-.
	.set L$set$61,LFE11213-LFB11213
	.quad L$set$61
	.uleb128 0x8
	.quad	0
	.align	3
LEFDE17:
LSFDE19:
	.set L$set$62,LEFDE19-LASFDE19
	.long L$set$62
LASFDE19:
	.long	LASFDE19-EH_frame1
	.quad	LFB11214-.
	.set L$set$63,LFE11214-LFB11214
	.quad L$set$63
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$64,LCFI43-LFB11214
	.long L$set$64
	.byte	0xe
	.uleb128 0x50
	.byte	0x9d
	.uleb128 0xa
	.byte	0x9e
	.uleb128 0x9
	.byte	0x4
	.set L$set$65,LCFI44-LCFI43
	.long L$set$65
	.byte	0x93
	.uleb128 0x8
	.byte	0x94
	.uleb128 0x7
	.byte	0x4
	.set L$set$66,LCFI45-LCFI44
	.long L$set$66
	.byte	0x95
	.uleb128 0x6
	.byte	0x96
	.uleb128 0x5
	.byte	0x4
	.set L$set$67,LCFI46-LCFI45
	.long L$set$67
	.byte	0x97
	.uleb128 0x4
	.byte	0x98
	.uleb128 0x3
	.byte	0x4
	.set L$set$68,LCFI47-LCFI46
	.long L$set$68
	.byte	0x99
	.uleb128 0x2
	.byte	0x4
	.set L$set$69,LCFI48-LCFI47
	.long L$set$69
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd9
	.byte	0xd7
	.byte	0xd8
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$70,LCFI49-LCFI48
	.long L$set$70
	.byte	0xb
	.align	3
LEFDE19:
LSFDE21:
	.set L$set$71,LEFDE21-LASFDE21
	.long L$set$71
LASFDE21:
	.long	LASFDE21-EH_frame1
	.quad	LFB11243-.
	.set L$set$72,LFE11243-LFB11243
	.quad L$set$72
	.uleb128 0x8
	.quad	0
	.align	3
LEFDE21:
LSFDE23:
	.set L$set$73,LEFDE23-LASFDE23
	.long L$set$73
LASFDE23:
	.long	LASFDE23-EH_frame1
	.quad	LFB11488-.
	.set L$set$74,LFE11488-LFB11488
	.quad L$set$74
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$75,LCFI50-LFB11488
	.long L$set$75
	.byte	0xe
	.uleb128 0x20
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$76,LCFI51-LCFI50
	.long L$set$76
	.byte	0x93
	.uleb128 0x2
	.byte	0x4
	.set L$set$77,LCFI52-LCFI51
	.long L$set$77
	.byte	0xde
	.byte	0xdd
	.byte	0xd3
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE23:
LSFDE25:
	.set L$set$78,LEFDE25-LASFDE25
	.long L$set$78
LASFDE25:
	.long	LASFDE25-EH_frame1
	.quad	LFB9825-.
	.set L$set$79,LFE9825-LFB9825
	.quad L$set$79
	.uleb128 0x8
	.quad	LLSDA9825-.
	.byte	0x4
	.set L$set$80,LCFI53-LFB9825
	.long L$set$80
	.byte	0xe
	.uleb128 0x80
	.byte	0x9d
	.uleb128 0x10
	.byte	0x9e
	.uleb128 0xf
	.byte	0x4
	.set L$set$81,LCFI54-LCFI53
	.long L$set$81
	.byte	0x93
	.uleb128 0xe
	.byte	0x94
	.uleb128 0xd
	.byte	0x4
	.set L$set$82,LCFI55-LCFI54
	.long L$set$82
	.byte	0x97
	.uleb128 0xa
	.byte	0x98
	.uleb128 0x9
	.byte	0x4
	.set L$set$83,LCFI56-LCFI55
	.long L$set$83
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd7
	.byte	0xd8
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$84,LCFI57-LCFI56
	.long L$set$84
	.byte	0xb
	.byte	0x4
	.set L$set$85,LCFI58-LCFI57
	.long L$set$85
	.byte	0x96
	.uleb128 0xb
	.byte	0x95
	.uleb128 0xc
	.byte	0x4
	.set L$set$86,LCFI59-LCFI58
	.long L$set$86
	.byte	0xa
	.byte	0xd6
	.byte	0xd5
	.byte	0x4
	.set L$set$87,LCFI60-LCFI59
	.long L$set$87
	.byte	0xde
	.byte	0xdd
	.byte	0xd7
	.byte	0xd8
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$88,LCFI61-LCFI60
	.long L$set$88
	.byte	0xb
	.byte	0x4
	.set L$set$89,LCFI62-LCFI61
	.long L$set$89
	.byte	0xa
	.byte	0xd6
	.byte	0xd5
	.byte	0x4
	.set L$set$90,LCFI63-LCFI62
	.long L$set$90
	.byte	0xb
	.align	3
LEFDE25:
LSFDE27:
	.set L$set$91,LEFDE27-LASFDE27
	.long L$set$91
LASFDE27:
	.long	LASFDE27-EH_frame1
	.quad	LFB11805-.
	.set L$set$92,LFE11805-LFB11805
	.quad L$set$92
	.uleb128 0x8
	.quad	LLSDA11805-.
	.byte	0x4
	.set L$set$93,LCFI64-LFB11805
	.long L$set$93
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$94,LCFI65-LCFI64
	.long L$set$94
	.byte	0x93
	.uleb128 0x4
	.byte	0x94
	.uleb128 0x3
	.byte	0x4
	.set L$set$95,LCFI66-LCFI65
	.long L$set$95
	.byte	0x95
	.uleb128 0x2
	.byte	0x96
	.uleb128 0x1
	.byte	0x4
	.set L$set$96,LCFI67-LCFI66
	.long L$set$96
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$97,LCFI68-LCFI67
	.long L$set$97
	.byte	0xb
	.align	3
LEFDE27:
LSFDE29:
	.set L$set$98,LEFDE29-LASFDE29
	.long L$set$98
LASFDE29:
	.long	LASFDE29-EH_frame1
	.quad	LFB11222-.
	.set L$set$99,LFE11222-LFB11222
	.quad L$set$99
	.uleb128 0x8
	.quad	LLSDA11222-.
	.byte	0x4
	.set L$set$100,LCFI69-LFB11222
	.long L$set$100
	.byte	0xe
	.uleb128 0x50
	.byte	0x9d
	.uleb128 0xa
	.byte	0x9e
	.uleb128 0x9
	.byte	0x4
	.set L$set$101,LCFI70-LCFI69
	.long L$set$101
	.byte	0x97
	.uleb128 0x4
	.byte	0x4
	.set L$set$102,LCFI71-LCFI70
	.long L$set$102
	.byte	0x95
	.uleb128 0x6
	.byte	0x96
	.uleb128 0x5
	.byte	0x4
	.set L$set$103,LCFI72-LCFI71
	.long L$set$103
	.byte	0x93
	.uleb128 0x8
	.byte	0x94
	.uleb128 0x7
	.byte	0x4
	.set L$set$104,LCFI73-LCFI72
	.long L$set$104
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd7
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$105,LCFI74-LCFI73
	.long L$set$105
	.byte	0xb
	.byte	0x4
	.set L$set$106,LCFI75-LCFI74
	.long L$set$106
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd7
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$107,LCFI76-LCFI75
	.long L$set$107
	.byte	0xb
	.align	3
LEFDE29:
LSFDE31:
	.set L$set$108,LEFDE31-LASFDE31
	.long L$set$108
LASFDE31:
	.long	LASFDE31-EH_frame1
	.quad	LFB11842-.
	.set L$set$109,LFE11842-LFB11842
	.quad L$set$109
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$110,LCFI77-LFB11842
	.long L$set$110
	.byte	0xe
	.uleb128 0x40
	.byte	0x9d
	.uleb128 0x8
	.byte	0x9e
	.uleb128 0x7
	.byte	0x4
	.set L$set$111,LCFI78-LCFI77
	.long L$set$111
	.byte	0x95
	.uleb128 0x4
	.byte	0x96
	.uleb128 0x3
	.byte	0x4
	.set L$set$112,LCFI79-LCFI78
	.long L$set$112
	.byte	0x93
	.uleb128 0x6
	.byte	0x94
	.uleb128 0x5
	.byte	0x4
	.set L$set$113,LCFI80-LCFI79
	.long L$set$113
	.byte	0x97
	.uleb128 0x2
	.byte	0x98
	.uleb128 0x1
	.byte	0x4
	.set L$set$114,LCFI81-LCFI80
	.long L$set$114
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd7
	.byte	0xd8
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$115,LCFI82-LCFI81
	.long L$set$115
	.byte	0xb
	.align	3
LEFDE31:
LSFDE33:
	.set L$set$116,LEFDE33-LASFDE33
	.long L$set$116
LASFDE33:
	.long	LASFDE33-EH_frame1
	.quad	LFB9866-.
	.set L$set$117,LFE9866-LFB9866
	.quad L$set$117
	.uleb128 0x8
	.quad	LLSDA9866-.
	.byte	0x4
	.set L$set$118,LCFI83-LFB9866
	.long L$set$118
	.byte	0xe
	.uleb128 0x170
	.byte	0x9d
	.uleb128 0x2e
	.byte	0x9e
	.uleb128 0x2d
	.byte	0x4
	.set L$set$119,LCFI84-LCFI83
	.long L$set$119
	.byte	0x93
	.uleb128 0x2c
	.byte	0x94
	.uleb128 0x2b
	.byte	0x95
	.uleb128 0x2a
	.byte	0x96
	.uleb128 0x29
	.byte	0x97
	.uleb128 0x28
	.byte	0x98
	.uleb128 0x27
	.byte	0x99
	.uleb128 0x26
	.byte	0x9a
	.uleb128 0x25
	.byte	0x9b
	.uleb128 0x24
	.byte	0x9c
	.uleb128 0x23
	.byte	0x4
	.set L$set$120,LCFI85-LCFI84
	.long L$set$120
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xdb
	.byte	0xdc
	.byte	0xd9
	.byte	0xda
	.byte	0xd7
	.byte	0xd8
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$121,LCFI86-LCFI85
	.long L$set$121
	.byte	0xb
	.align	3
LEFDE33:
LSFDE35:
	.set L$set$122,LEFDE35-LASFDE35
	.long L$set$122
LASFDE35:
	.long	LASFDE35-EH_frame1
	.quad	LFB12329-.
	.set L$set$123,LFE12329-LFB12329
	.quad L$set$123
	.uleb128 0x8
	.quad	0
	.byte	0x4
	.set L$set$124,LCFI87-LFB12329
	.long L$set$124
	.byte	0xe
	.uleb128 0x20
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$125,LCFI88-LCFI87
	.long L$set$125
	.byte	0x93
	.uleb128 0x2
	.byte	0x4
	.set L$set$126,LCFI89-LCFI88
	.long L$set$126
	.byte	0xde
	.byte	0xdd
	.byte	0xd3
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE35:
	.private_extern ___dso_handle
	.ident	"GCC: (Homebrew GCC 12.2.0) 12.2.0"
	.mod_init_func
_Mod.init:
	.align	3
	.xword	__GLOBAL__sub_I_main.cpp
	.subsections_via_symbols
