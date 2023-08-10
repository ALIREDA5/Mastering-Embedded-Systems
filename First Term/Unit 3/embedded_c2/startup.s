/* startup_cortex-m3 */
/*  SRAM  0x20001000 */

.section  .vectors

.word   0x20001000
.word   reset
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
reset:
      bl    main
stop: b    stop

.thumb_func

Vector_handler:
	b reset
