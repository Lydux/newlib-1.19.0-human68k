| void _iocs_adpcmain (const struct _iocs_chain *, int, int);
.text
.even
.global _iocs_adpcmain
.type _iocs_adpcmain,@function
_iocs_adpcmain:
	move.l	%d2, %sp@-
	movem.l	%sp@(8), %d0-%d2
	move.l	%d0, %a1
	moveq	#0x63, %d0
	trap	#15
	move.l	%sp@+, %d2
	rts
