#include "instructions.h"

static const t_instruction	g_instructions[] = {
    /*
    **                              8-BIT LOADS
    ** _________________________________________________________________________
    */

    // lD nn, d8 : put value nn into d8.
    [0x06] = {"LD B, d8",		&instr_ld_b_d8,		2,	8},
    [0x0E] = {"LD C, d8",		&instr_ld_c_d8,		2,	8},
    [0x16] = {"LD D, d8",		&instr_ld_d_d8,		2,	8},
    [0x1E] = {"LD E, d8",		&instr_ld_e_d8,		2,	8},
    [0x26] = {"LD H, d8",		&instr_ld_h_d8,		2,	8},
    [0x2E] = {"LD L, d8",		&instr_ld_l_d8,		2,	8},

    // LD r1, r2 : put value r2 into r1.
    [0x7F] = {"LD A, A",		&instr_ld_a_a,		1,	4},
    [0x78] = {"LD A, B",		&instr_ld_a_b,		1,	4},
    [0x79] = {"LD A, C",		&instr_ld_a_c,		1,	4},
    [0x7A] = {"LD A, D",		&instr_ld_a_d,		1,	4},
    [0x7B] = {"LD A, E",		&instr_ld_a_e,		1,	4},
    [0x7C] = {"LD A, H",		&instr_ld_a_h,		1,	4},
    [0x7D] = {"LD A, L",		&instr_ld_a_l,		1,	4},
    [0x7D] = {"LD A, (HL)",		&instr_ld_a_hl,		1,	8},

    [0x40] = {"LD B, B",		&instr_ld_b_b,		1,	4},
    [0x41] = {"LD B, C",		&instr_ld_b_c,		1,	4},
    [0x42] = {"LD B, D",		&instr_ld_b_d,		1,	4},
    [0x43] = {"LD B, E",		&instr_ld_b_e,		1,	4},
    [0x44] = {"LD B, H",		&instr_ld_b_h,		1,	4},
    [0x45] = {"LD B, L",		&instr_ld_b_l,		1,	4},
    [0x46] = {"LD B, (HL)",		&instr_ld_b_hl,		1,	8},

    [0x48] = {"LD C, B",		&instr_ld_c_b,		1,	4},
    [0x49] = {"LD C, C",		&instr_ld_c_c,		1,	4},
    [0x4A] = {"LD C, D",		&instr_ld_c_d,		1,	4},
    [0x4B] = {"LD C, E",		&instr_ld_c_e,		1,	4},
    [0x4C] = {"LD C, H",		&instr_ld_c_h,		1,	4},
    [0x4D] = {"LD C, L",		&instr_ld_c_l,		1,	4},
    [0x4E] = {"LD C, (HL)",		&instr_ld_c_hl,		1,	8},

    [0x50] = {"LD D, B",		&instr_ld_d_b,		1,	4},
    [0x51] = {"LD D, C",		&instr_ld_d_c,		1,	4},
    [0x52] = {"LD D, D",		&instr_ld_d_d,		1,	4},
    [0x53] = {"LD D, E",		&instr_ld_d_e,		1,	4},
    [0x54] = {"LD D, H",		&instr_ld_d_h,		1,	4},
    [0x55] = {"LD D, L",		&instr_ld_d_l,		1,	4},
    [0x56] = {"LD D, (HL)",		&instr_ld_d_hl,		1,	8},

    [0x58] = {"LD E, B",		&instr_ld_e_b,		1,	4},
    [0x59] = {"LD E, C",		&instr_ld_e_c,		1,	4},
    [0x5A] = {"LD E, D",		&instr_ld_e_d,		1,	4},
    [0x5B] = {"LD E, E",		&instr_ld_e_e,		1,	4},
    [0x5C] = {"LD E, H",		&instr_ld_e_h,		1,	4},
    [0x5D] = {"LD E, L",		&instr_ld_e_l,		1,	4},
    [0x5E] = {"LD E, (HL)",		&instr_ld_e_hl,		1,	8},

    [0x60] = {"LD H, B",		&instr_ld_h_b,		1,	4},
    [0x61] = {"LD H, C",		&instr_ld_h_c,		1,	4},
    [0x62] = {"LD H, D",		&instr_ld_h_d,		1,	4},
    [0x63] = {"LD H, E",		&instr_ld_h_e,		1,	4},
    [0x64] = {"LD H, H",		&instr_ld_h_h,		1,	4},
    [0x65] = {"LD H, L",		&instr_ld_h_l,		1,	4},
    [0x66] = {"LD H, (HL)",		&instr_ld_h_hl,		1,	8},

    [0x68] = {"LD L, B",		&instr_ld_l_b,		1,	4},
    [0x69] = {"LD L, C",		&instr_ld_l_c,		1,	4},
    [0x6A] = {"LD L, D",		&instr_ld_l_d,		1,	4},
    [0x6B] = {"LD L, E",		&instr_ld_l_e,		1,	4},
    [0x6C] = {"LD L, H",		&instr_ld_l_h,		1,	4},
    [0x6D] = {"LD L, L",		&instr_ld_l_l,		1,	4},
    [0x6E] = {"LD L, (HL)",		&instr_ld_l_hl,		1,	8},

    [0x70] = {"LD (HL), B",		&instr_ld_hl_b,		1,	8},
    [0x71] = {"LD (HL), C",		&instr_ld_hl_c,		1,	8},
    [0x72] = {"LD (HL), D",		&instr_ld_hl_d,		1,	8},
    [0x73] = {"LD (HL), E",		&instr_ld_hl_e,		1,	8},
    [0x74] = {"LD (HL), H",		&instr_ld_hl_h,		1,	8},
    [0x75] = {"LD (HL), L",		&instr_ld_hl_l,		1,	8},
    [0x36] = {"LD (HL), d8",		&instr_ld_hl_d8,	2,	12},

    // LD A, n : put value n into A.
    [0x0A] = {"LD A, (BC)",		&instr_ld_a_bc,		1,	8},
    [0x1A] = {"LD A, (DE)",		&instr_ld_a_de,		1,	8},
    [0x7E] = {"LD A, (HL)",		&instr_ld_a_hl,		1,	8},
    [0xFA] = {"LD A, (a16)",		&instr_ld_a_a16,	3,	16},
    [0x3E] = {"LD A, (d8)",		&instr_ld_a_d8,		2,	8},

    // LD n, A : put value A into n.
    [0x47] = {"LD B, A",		&instr_ld_b_a,		1,	4},
    [0x4F] = {"LD C, A",		&instr_ld_c_a,		1,	4},
    [0x57] = {"LD D, A",		&instr_ld_d_a,		1,	4},
    [0x5F] = {"LD E, A",		&instr_ld_e_a,		1,	4},
    [0x67] = {"LD H, A",		&instr_ld_h_a,		1,	4},
    [0x6F] = {"LD L, A",		&instr_ld_l_a,		1,	4},
    [0x02] = {"LD (BC), A",		&instr_ld_bc_a,		1,	8},
    [0x12] = {"LD (DE), A",		&instr_ld_de_a,		1,	8},
    [0x77] = {"LD (HL), A",		&instr_ld_hl_a,		1,	8},
    [0xEA] = {"LD (a16), A",		&instr_ld_a16_a,	3,	16},

    // LD A, (C) : put value at address $FF00 + register C into A.
    // Same as : LD A, ($FF00 + C)
    [0xF2] = {"LD A, (C)",		&instr_ld_a_c_ff00,	2,	8},

    // LD (C), A : put A into address $FF00 + register C.
    [0xE2] = {"LD (C), A",		&instr_ld_c_a_ff00,	2,	8},

    // LDD A, (HL) : put value at address HL into A. Decrement HL.
    [0x3A] = {"LD A, (HL-) | LD A, (HLD) | LDD A, (HL)",		&instr_ldd_a_hl,	1,	8},

    // LDD (HL), A : put A into memory address HL. Decrement HL.
    [0x32] = {"LD (HL-), A | LD (HLD), A | LDD (HL), A",		&instr_ldd_hl_a,	1,	8},

    // LDI A, (HL) : put value at address HL into A. Increment HL.
    [0x3A] = {"LD A, (HL-) | LD A, (HLD) | LDI A, (HL)",		&instr_ldi_a_hl,	1,	8},

    // LDI (HL), A : put A into memory address HL. Increment HL.
    [0x32] = {"LD (HL-), A | LD (HLD), A | LDI (HL), A",		&instr_ldi_hl_a,	1,	8},

    // LDH (d8), A : put A into memory address $FF00 + d8.
    [0xE0] = {"LDH (d8), A | LD ($FF00 + d8), A",			&instr_ldh_n_a,		2,	12},

    // LDH A, (d8) : put memory address $FF00 + d8 into A.
    [0xF0] = {"LDH A, (d8) | LD A, ($FF00 + d8)",			&instr_ldh_a_n,		2,	12},

    /*
    **                              16-BIT LOADS
    ** _________________________________________________________________________
    */

    // LD r, d16 : put value d16 into r.
    [0x01] = {"LD BC, d16",		&instr_ld_bc_d16,	3,	12},
    [0x11] = {"LD DE, d16",		&instr_ld_de_d16,	3,	12},
    [0x21] = {"LD HL, d16",		&instr_hl_de_d16,	3,	12},
    [0x31] = {"LD SP, d16",		&instr_hl_sp_d16,	3,	12},

    // LD SP, HL : put HL into SP.
    [0xF9] = {"LD SP, HL",		&instr_hl_sp_hl,	1,	8},

    // LDHL SP, d8 : put SP + d8 effective address into HL.
    [0xF8] = {"LDHL SP, d8",		&instr_ldhl_sp_d8,	2,	12},

    // LD d16, SP : put SP at address d16.
    [0x08] = {"LD (d16), SP",		&instr_ld_d16_sp,	3,	20},

    // PUSH rr : push register pair rr onto stack. Decrement SP tw	ce.
    [0xF5] = {"PUSH AF",		&instr_push_af,		1,	16},
    [0xC5] = {"PUSH BC",		&instr_push_bc,		1,	16},
    [0xD5] = {"PUSH DE",		&instr_push_de,		1,	16},
    [0xE5] = {"PUSH HL",		&instr_push_hl,		1,	16},

    // POP r : pop two bytes off stack into register pair r. Incre	ent SP twice.
    [0xF1] = {"POP AF",			&instr_pop_af,		1,	12},
    [0xC1] = {"POP BC",			&instr_pop_bc,		1,	12},
    [0xD1] = {"POP DE",			&instr_pop_de,		1,	12},
    [0xE1] = {"POP HL",			&instr_pop_hl,		1,	12},

    /*
    **                              8-BIT ALU
    ** ___________________________________________________________	_____________
    */

    // ADD A, r : add r to A.
    [0x87] = {"ADD A, A",		&instr_add_a_a,		1,	4},
    [0x80] = {"ADD A, B",		&instr_add_a_b,		1,	4},
    [0x81] = {"ADD A, C",		&instr_add_a_c,		1,	4},
    [0x82] = {"ADD A, D",		&instr_add_a_d,		1,	4},
    [0x83] = {"ADD A, E",		&instr_add_a_e,		1,	4},
    [0x84] = {"ADD A, H",		&instr_add_a_h,		1,	4},
    [0x85] = {"ADD A, L",		&instr_add_a_l,		1,	4},
    [0x86] = {"ADD A, (HL)",		&instr_add_a_hl,	1,	8},
    [0xC6] = {"ADD A, d8",		&instr_add_a_d8,	2,	8},

    // ADC A, r : add r + Carry flag to A.
    [0x8F] = {"ADC A, A",		&instr_adc_a_a,		1,	4},
    [0x88] = {"ADC A, B",		&instr_adc_a_b,		1,	4},
    [0x89] = {"ADC A, C",		&instr_adc_a_c,		1,	4},
    [0x8A] = {"ADC A, D",		&instr_adc_a_d,		1,	4},
    [0x8B] = {"ADC A, E",		&instr_adc_a_e,		1,	4},
    [0x8C] = {"ADC A, H",		&instr_adc_a_h,		1,	4},
    [0x8D] = {"ADC A, L",		&instr_adc_a_l,		1,	4},
    [0x8E] = {"ADC A, (HL)",		&instr_adc_a_hl,	1,	8},
    [0xCE] = {"ADC A, d8",		&instr_adc_a_d8,	2,	8},

    // SUB r : substract r to A.
    [0x97] = {"SUB A, A",		&instr_sub_a_a,		1,	4},
    [0x90] = {"SUB A, B",		&instr_sub_a_b,		1,	4},
    [0x91] = {"SUB A, C",		&instr_sub_a_c,		1,	4},
    [0x92] = {"SUB A, D",		&instr_sub_a_d,		1,	4},
    [0x93] = {"SUB A, E",		&instr_sub_a_e,		1,	4},
    [0x94] = {"SUB A, H",		&instr_sub_a_h,		1,	4},
    [0x95] = {"SUB A, L",		&instr_sub_a_l,		1,	4},
    [0x96] = {"SUB A, (HL)",		&instr_sub_a_hl,	1,	8},
    [0xD6] = {"SUB A, d8",		&instr_sub_a_d8,	2,	8},

    // SBC A, r : substract r + Carry flag from A.
    [0x9F] = {"SBC A, A",		&instr_sbc_a_a,		1,	4},
    [0x98] = {"SBC A, B",		&instr_sbc_a_b,		1,	4},
    [0x99] = {"SBC A, C",		&instr_sbc_a_c,		1,	4},
    [0x9A] = {"SBC A, D",		&instr_sbc_a_d,		1,	4},
    [0x9B] = {"SBC A, E",		&instr_sbc_a_e,		1,	4},
    [0x9C] = {"SBC A, H",		&instr_sbc_a_h,		1,	4},
    [0x9D] = {"SBC A, L",		&instr_sbc_a_l,		1,	4},
    [0x9E] = {"SBC A, (HL)",		&instr_sbc_a_hl,	1,	8},
    [0xDE] = {"SBC A, d8",		&instr_sbc_a_d8,	2,	8}, // ATTENTION, indefini dans le GameBoy CPU Manual

    // AND r : logically AND r with A, result in A.
    [0xA7] = {"AND A, A",		&instr_and_a_a,		1,	4},
    [0xA0] = {"AND A, B",		&instr_and_a_b,		1,	4},
    [0xA1] = {"AND A, C",		&instr_and_a_c,		1,	4},
    [0xA2] = {"AND A, D",		&instr_and_a_d,		1,	4},
    [0xA3] = {"AND A, E",		&instr_and_a_e,		1,	4},
    [0xA4] = {"AND A, H",		&instr_and_a_h,		1,	4},
    [0xA5] = {"AND A, L",		&instr_and_a_l,		1,	4},
    [0xA6] = {"AND A, (HL)",		&instr_and_a_hl,	1,	8},
    [0xE6] = {"AND A, d8",		&instr_and_a_d8,	2,	8},

    // OR r : logical OR r with A, result in A.
    [0xB7] = {"OR A, A",		&instr_or_a_a,		1,	4},
    [0xB0] = {"OR A, B",		&instr_or_a_b,		1,	4},
    [0xB1] = {"OR A, C",		&instr_or_a_c,		1,	4},
    [0xB2] = {"OR A, D",		&instr_or_a_d,		1,	4},
    [0xB3] = {"OR A, E",		&instr_or_a_e,		1,	4},
    [0xB4] = {"OR A, H",		&instr_or_a_h,		1,	4},
    [0xB5] = {"OR A, L",		&instr_or_a_l,		1,	4},
    [0xB6] = {"OR A, (HL)",		&instr_or_a_hl,		1,	8},
    [0xF6] = {"OR A, d8",		&instr_or_a_d8,		2,	8},

    // XOR r : logical XOR r with A, result in A.
    [0xAF] = {"XOR A, A",		&instr_xor_a_a,		1,	4},
    [0xA8] = {"XOR A, B",		&instr_xor_a_b,		1,	4},
    [0xA9] = {"XOR A, C",		&instr_xor_a_c,		1,	4},
    [0xAA] = {"XOR A, D",		&instr_xor_a_d,		1,	4},
    [0xAB] = {"XOR A, E",		&instr_xor_a_e,		1,	4},
    [0xAC] = {"XOR A, H",		&instr_xor_a_h,		1,	4},
    [0xAD] = {"XOR A, L",		&instr_xor_a_l,		1,	4},
    [0xAE] = {"XOR A, (HL)",		&instr_xor_a_hl,	1,	8},
    [0xEE] = {"XOR A, d8",		&instr_xor_a_d8,	2,	8},

    // CP r : compare A with n. This is A - r.
    [0xBF] = {"CP A, A",		&instr_cp_a_a,		1,	4},
    [0xB8] = {"CP A, B",		&instr_cp_a_b,		1,	4},
    [0xB9] = {"CP A, C",		&instr_cp_a_c,		1,	4},
    [0xBA] = {"CP A, D",		&instr_cp_a_d,		1,	4},
    [0xBB] = {"CP A, E",		&instr_cp_a_e,		1,	4},
    [0xBC] = {"CP A, H",		&instr_cp_a_h,		1,	4},
    [0xBD] = {"CP A, L",		&instr_cp_a_l,		1,	4},
    [0xBE] = {"CP A, (HL)",		&instr_cp_a_hl,		1,	8},
    [0xFE] = {"CP A, d8",		&instr_cp_a_d8,		2,	8},

    // INC r : decrement register n.
    [0x3C] = {"INC A, A",		&instr_inc_a_a,		1,	4},
    [0x04] = {"INC A, B",		&instr_inc_a_b,		1,	4},
    [0x0C] = {"INC A, C",		&instr_inc_a_c,		1,	4},
    [0x14] = {"INC A, D",		&instr_inc_a_d,		1,	4},
    [0x1C] = {"INC A, E",		&instr_inc_a_e,		1,	4},
    [0x24] = {"INC A, H",		&instr_inc_a_h,		1,	4},
    [0x2C] = {"INC A, L",		&instr_inc_a_l,		1,	4},
    [0x34] = {"INC A, (HL)",		&instr_inc_a_hl,	1,	12},

    // DEC r : decrement register n.
    [0x3D] = {"DEC A, A",		&instr_dec_a_a,		1,	4},
    [0x05] = {"DEC A, B",		&instr_dec_a_b,		1,	4},
    [0x0D] = {"DEC A, C",		&instr_dec_a_c,		1,	4},
    [0x15] = {"DEC A, D",		&instr_dec_a_d,		1,	4},
    [0x1D] = {"DEC A, E",		&instr_dec_a_e,		1,	4},
    [0x25] = {"DEC A, H",		&instr_dec_a_h,		1,	4},
    [0x2D] = {"DEC A, L",		&instr_dec_a_l,		1,	4},
    [0x35] = {"DEC A, (HL)",		&instr_dec_a_hl,	1,	12},

    /*
    **                           16-BIT ARITHMETIC
    ** ________________________________________________________________________
    */

    // ADD HL, rr : add rr to HL.
    [0x09] = {"ADD HL, BC",		&instr_add_hl_bc,	1,	8},
    [0x19] = {"ADD HL, DE",		&instr_add_hl_de,	1,	8},
    [0x29] = {"ADD HL, HL",		&instr_add_hl_hl,	1,	8},
    [0x39] = {"ADD HL, SP",		&instr_add_hl_sp,	1,	8},

    // ADD SP, r8 : add r8 to SP.
    [0xE8] = {"ADD SP, r8",		&instr_add_sp_r8,	2,	16},

    // INC rr : increment register rr.
    [0x03] = {"INC BC",			&instr_inc_bc,		1,	8},
    [0x13] = {"INC DE",			&instr_inc_de,		1,	8},
    [0x23] = {"INC HL",			&instr_inc_hl,		1,	8},
    [0x33] = {"INC SP",			&instr_inc_sp,		1,	8},

    // DEC rr : decrement register rr.
    [0x0B] = {"DEC BC",			&instr_dec_bc,		1,	8},
    [0x1B] = {"DEC DE",			&instr_dec_de,		1,	8},
    [0x2B] = {"DEC HL",			&instr_dec_hl,		1,	8},
    [0x3B] = {"DEC SP",			&instr_dec_sp,		1,	8},

    /*
    **                               MISCELLANEOUS
    ** ________________________________________________________________________
    */

    // DAA : decimal adjust register A.
    // This instruction adjusts register A so that the correct representation
    // of Binary Coded Decimal (BCD) is obtained.
    [0x27] = {"DAA",			&instr_daa,		1,	4},

    // CPL : complement A register. (Flip all bits.)
    [0x2F] = {"CPL",			&instr_cpl,		1,	4},

    // CCF : complement carry flag. (Flip it.)
    [0x3F] = {"CCF",			&instr_ccf,		1,	4},

    // SCF : set carry flag.
    [0x37] = {"SCF",			&instr_scf,		1,	4},

    // NOP : no operation.
    [0x00] = {"NOP",			&instr_nop,		1,	4},

    // HALT : power down CPU until an interrupt occurs. Use
    // this when ever possible to reduce energy consumption.
    [0x76] = {"HALT",			&instr_halt,		1,	4},

    // STOP : halt CPU and LCD display until button is pressed.
    [0x10] = {"STOP",			&instr_stop,		1,	4},

    // DI : disables interrupts but not immediately. Interrupts are disabled
    // after instruction after DI is executed.
    [0xF3] = {"DI",			&instr_di,		1,	4},

    // EI : enable interrupts but not immediately. Interrupts are enabled
    // after instruction after EI is executed.
    [0xFB] = {"EI",			&instr_ei,		1,	4},

    /*
    **                             ROTATES & SHIFTS
    ** ________________________________________________________________________
    */

    // RLCA : rotate A left. Old bit 7 to Carry flag.
    [0x07] = {"RLCA",			&instr_rlca,		1,	4},

    // RLA : rotate A left through Carry flag.
    [0x17] = {"RLA",			&instr_rla,		1,	4},

    // RRCA : rotate A right. Old bit 0 to Carry flag.
    [0x0F] = {"RRCA",			&instr_rrca,		1,	4},

    // RRA : rotate A right through Carry flag.
    [0x1F] = {"RRA",			&instr_rra,		1,	4},

    /*
    **                                   JUMPS
    ** ________________________________________________________________________
    */

    // JP a16 : jump to address a16.
    [0xC3] = {"JP a16",			&instr_jp_a16,		3,	16},

    // JP cond, a16 : jump to address a16 if following condition is true :
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0xC2] = {"JP NZ, a16",		&instr_jp_nz_a16,	3,	12},
    [0xCA] = {"JP Z, a16",		&instr_jp_z_a16,	3,	12},
    [0xD2] = {"JP NC, a16",		&instr_jp_nc_a16,	3,	12},
    [0xDA] = {"JP C, a16",		&instr_jp_c_a16,	3,	12},

    // JP (HL) : jump to address contained in HL.
    [0xE9] = {"JP (HL)",		&instr_jp_hl,		1,	4},

    // JR r8 : add n to current address and jump to it.
    [0x18] = {"JR r8",			&instr_jr_r8,		1,	8},

    // JR r8 : if following condition is true then add n to current address
    // and jump to it.
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0x20] = {"JR NZ, r8",		&instr_jr_nz_r8,	2,	8},
    [0x28] = {"JR Z, r8",		&instr_jr_z_r8,		2,	8},
    [0x30] = {"JR NC, r8",		&instr_jr_nc_r8,	2,	8},
    [0x38] = {"JR C, r8",		&instr_jr_c_r8,		2,	8},

    /*
    **                                   CALLS
    ** ________________________________________________________________________
    */

    // CALL a16 : push address of next instruction onto stack
    // and then jump to address a16.

    [0xCD] = {"CALL a16",		&instr_call_a16,	3,	12},

    // CALL cond, a16 : call address a16 if following condition is true :
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0xC4] = {"CALL NZ, a16",		&instr_call_nz_a16,	3,	12},
    [0xCC] = {"CALL Z, a16",		&instr_call_z_a16,	3,	12},
    [0xD4] = {"CALL NC, a16",		&instr_call_nc_a16,	3,	12},
    [0xDC] = {"CALL C, a16",		&instr_call_c_a16,	3,	12},

    /*
    **                               RESTARTS
    ** ________________________________________________________________________
    */

    // RST n : push present address onto stack. Jump to address $0000 + n.
    [0xC7] = {"RST 0x00",		&instr_rst_00,		1,	32},
    [0xCF] = {"RST 0x08",		&instr_rst_08,		1,	32},
    [0xD7] = {"RST 0x10",		&instr_rst_10,		1,	32},
    [0xDF] = {"RST 0x18",		&instr_rst_18,		1,	32},
    [0xE7] = {"RST 0x20",		&instr_rst_20,		1,	32},
    [0xEF] = {"RST 0x28",		&instr_rst_28,		1,	32},
    [0xF7] = {"RST 0x30",		&instr_rst_30,		1,	32},
    [0xFF] = {"RST 0x38",		&instr_rst_38,		1,	32},

    /*
    **                               RETURNS
    ** ________________________________________________________________________
    */

    // RET : pop two bytes from stack and jump to that address.
    [0xC9] = {"RET",			&instr_ret,		1,	8},

    // RET cond : return if following condition is true :
    // cond = NZ, Jump if Z flag is reset.
    // cond = Z,  Jump if Z flag is set.
    // cond = NC, Jump if C flag is reset.
    // cond = C,  Jump if C flag is set.
    [0xC0] = {"RET NZ",			&instr_ret_nz,		1,	8},
    [0xC8] = {"RET Z",			&instr_ret_z,		1,	8},
    [0xD0] = {"RET NC",			&instr_ret_nc,		1,	8},
    [0xD8] = {"RET C",			&instr_ret_c,		1,	8},

    // RETI : pop two bytes from stack & jump
    // to that address then enable interrupts.
    [0xD9] = {"RETI",			&instr_reti,		1,	8},

};
