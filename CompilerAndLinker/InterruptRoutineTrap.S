.extern handleSupervisorTrap
.global supervisorTrap
.align 4
supervisorTrap:

    addi sp, sp, -256

    sd x0, 0x00(sp)
    sd x1, 0x08(sp)
    sd x2, 0x10(sp)
    sd x3, 0x18(sp)
    sd x4, 0x20(sp)
    sd x5, 0x28(sp)

    # ... Saving all registers from x0 to x31

    call handleSupervisorTrap

    ld x0, 0x00(sp)
    ld x1, 0x08(sp)
    ld x2, 0x10(sp)
    ld x3, 0x18(sp)
    ld x4, 0x20(sp)
    ld x5, 0x28(sp)

    # ... Reading all registers from x0 to x31

    addi sp, sp, 256

    sret #supervisor ret