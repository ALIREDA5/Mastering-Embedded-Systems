/* startup_cortex-m3 */
/*  SRAM  0x20001000 */

.section  .vectors

.word   0x20001000
.word   _reset
.word   Vector_handler  /* NMI */
.word   Vector_handler  /* Hard fault */
.word   Vector_handler
.word   Vector_handler
.word   Vector_handler
.word   Vector_handler
.word   Vector_handler
.word   Vector_handler
.word   Vector_handler
.word   Vector_handler


.section  .text

.global reset
_reset:
      bl    main
stop: b    stop

.thumb_func

Vector_handler:
	b _reset
