ENTRY(loader)                /* the name of the entry label */

SECTIONS {
    . = 1M;          /* the code should be loaded at 1 MB  <- 0x00100000*/

    .text ALIGN (4K) :   /* align at 4 KB  <-- 0x1000*/
    {
        *(.text)             /* all text sections from all files */
    }

    .rodata ALIGN (4K) : /* align at 4 KB <- 0x1000*/
    {
        *(.rodata*)          /* all read-only data sections from all files */
    }

    .data ALIGN (4M) :   /* align at 4 KB <- 0x1000 */
    {
        *(.data)             /* all data sections from all files */
    }

    .bss ALIGN (4M) :    /* align at 4 KB <- 0x1000*/
    {
        *(COMMON)            /* all COMMON sections from all files */
        *(.bss)              /* all bss sections from all files */
    }
}