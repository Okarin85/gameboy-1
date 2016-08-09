#include "instructions.h"

static const t_instruction	g_cb_instrctions[] {
    /*
    **                           MISCELLANEOUS
    ** ________________________________________________________________________
    */

    // SWAP upper & lower nibles of n.
    [0x37] = {"SWAP A, A",		&instr_swap_a_a,	2,	4},
    [0x30] = {"SWAP A, B",		&instr_swap_a_b,	2,	4},
    [0x31] = {"SWAP A, C",		&instr_swap_a_c,	2,	4},
    [0x32] = {"SWAP A, D",		&instr_swap_a_d,	2,	4},
    [0x33] = {"SWAP A, E",		&instr_swap_a_e,	2,	4},
    [0x34] = {"SWAP A, H",		&instr_swap_a_h,	2,	4},
    [0x35] = {"SWAP A, L",		&instr_swap_a_l,	2,	4},
    [0x36] = {"SWAP A, (HL)",		&instr_swap_a_hl,	2,	8},

    /*
    **                             ROTATES & SHIFTS
    ** ________________________________________________________________________
    */

    // RLC r : rotate r left. Old bit 7 to Carry flag.
    [0x07] = {"RLC A",			&instr_rlc_a,		2,	8},
    [0x00] = {"RLC B",			&instr_rlc_b,		2,	8},
    [0x01] = {"RLC C",			&instr_rlc_c,		2,	8},
    [0x02] = {"RLC D",			&instr_rlc_d,		2,	8},
    [0x03] = {"RLC E",			&instr_rlc_e,		2,	8},
    [0x04] = {"RLC H",			&instr_rlc_h,		2,	8},
    [0x05] = {"RLC L",			&instr_rlc_l,		2,	8},
    [0x06] = {"RLC (HL)",		&instr_rlc_hl,		2,	16},

    // RL r : rotate r left through Carry flag.
    [0x17] = {"RL A",			&instr_rl_a,		2,	8},
    [0x10] = {"RL B",			&instr_rl_b,		2,	8},
    [0x11] = {"RL C",			&instr_rl_c,		2,	8},
    [0x12] = {"RL D",			&instr_rl_d,		2,	8},
    [0x13] = {"RL E",			&instr_rl_e,		2,	8},
    [0x14] = {"RL H",			&instr_rl_h,		2,	8},
    [0x15] = {"RL L",			&instr_rl_l,		2,	8},
    [0x16] = {"RL (HL)",		&instr_rl_hl,		2,	16},

    // RRC r : rotate r right. Old bit 0 to Carry flag.
    [0x0F] = {"RRC A",			&instr_rrc_a,		2,	8},
    [0x08] = {"RRC B",			&instr_rrc_b,		2,	8},
    [0x09] = {"RRC C",			&instr_rrc_c,		2,	8},
    [0x0A] = {"RRC D",			&instr_rrc_d,		2,	8},
    [0x0B] = {"RRC E",			&instr_rrc_e,		2,	8},
    [0x0C] = {"RRC H",			&instr_rrc_h,		2,	8},
    [0x0D] = {"RRC L",			&instr_rrc_l,		2,	8},
    [0x0E] = {"RRC (HL)",		&instr_rrc_hl,		2,	16},

    // RR r : rotate r right through Carry flag.
    [0x1F] = {"RR A",			&instr_rr_a,		2,	8},
    [0x18] = {"RR B",			&instr_rr_b,		2,	8},
    [0x19] = {"RR C",			&instr_rr_c,		2,	8},
    [0x1A] = {"RR D",			&instr_rr_d,		2,	8},
    [0x1B] = {"RR E",			&instr_rr_e,		2,	8},
    [0x1C] = {"RR H",			&instr_rr_h,		2,	8},
    [0x1D] = {"RR L",			&instr_rr_l,		2,	8},
    [0x1E] = {"RR (HL)",		&instr_rr_hl,		2,	16},

    // SLA r : shift r left into Carry. LSB of r set to 0.
    [0x27] = {"SLA A",			&instr_sla_a,		2,	8},
    [0x20] = {"SLA B",			&instr_sla_b,		2,	8},
    [0x21] = {"SLA C",			&instr_sla_c,		2,	8},
    [0x22] = {"SLA D",			&instr_sla_d,		2,	8},
    [0x23] = {"SLA E",			&instr_sla_e,		2,	8},
    [0x24] = {"SLA H",			&instr_sla_h,		2,	8},
    [0x25] = {"SLA L",			&instr_sla_l,		2,	8},
    [0x26] = {"SLA (HL)",		&instr_sla_hl,		2,	16},

    // SRA r :  shift r right into Carry. MSB doesn't change.
    [0x2F] = {"SRA A",			&instr_sra_a,		2,	8},
    [0x28] = {"SRA B",			&instr_sra_b,		2,	8},
    [0x29] = {"SRA C",			&instr_sra_c,		2,	8},
    [0x2A] = {"SRA D",			&instr_sra_d,		2,	8},
    [0x2B] = {"SRA E",			&instr_sra_e,		2,	8},
    [0x2C] = {"SRA H",			&instr_sra_h,		2,	8},
    [0x2D] = {"SRA L",			&instr_sra_l,		2,	8},
    [0x2E] = {"SRA (HL)",		&instr_sra_hl,		2,	16},

    // SRL r :  shift r right into Carry. MSB set to 0.
    [0x3F] = {"SRL A",			&instr_srl_a,		2,	8},
    [0x38] = {"SRL B",			&instr_srl_b,		2,	8},
    [0x39] = {"SRL C",			&instr_srl_c,		2,	8},
    [0x3A] = {"SRL D",			&instr_srl_d,		2,	8},
    [0x3B] = {"SRL E",			&instr_srl_e,		2,	8},
    [0x3C] = {"SRL H",			&instr_srl_h,		2,	8},
    [0x3D] = {"SRL L",			&instr_srl_l,		2,	8},
    [0x3E] = {"SRL (HL)",		&instr_srl_hl,		2,	16},

    // BIT 0, r : test bit 0 in register r.
    [0x47] = {"BIT 0, A",		&instr_bit_0_a,		2,	8},
    [0x40] = {"BIT 0, B",		&instr_bit_0_b,		2,	8},
    [0x41] = {"BIT 0, C",		&instr_bit_0_c,		2,	8},
    [0x42] = {"BIT 0, D",		&instr_bit_0_d,		2,	8},
    [0x43] = {"BIT 0, E",		&instr_bit_0_e,		2,	8},
    [0x44] = {"BIT 0, H",		&instr_bit_0_h,		2,	8},
    [0x45] = {"BIT 0, L",		&instr_bit_0_l,		2,	8},
    [0x46] = {"BIT 0, (HL)",		&instr_bit_0_hl,	2,	16},

    // BIT 1, r : test bit 1 in register r.
    [0x4F] = {"BIT 1, A",		&instr_bit_1_a,		2,	8},
    [0x48] = {"BIT 1, B",		&instr_bit_1_b,		2,	8},
    [0x49] = {"BIT 1, C",		&instr_bit_1_c,		2,	8},
    [0x4A] = {"BIT 1, D",		&instr_bit_1_d,		2,	8},
    [0x4B] = {"BIT 1, E",		&instr_bit_1_e,		2,	8},
    [0x4C] = {"BIT 1, H",		&instr_bit_1_h,		2,	8},
    [0x4D] = {"BIT 1, L",		&instr_bit_1_l,		2,	8},
    [0x4E] = {"BIT 1, (HL)",		&instr_bit_1_hl,	2,	16},

    // BIT 2, r : test bit 2 in register r.
    [0x57] = {"BIT 2, A",		&instr_bit_2_a,		2,	8},
    [0x50] = {"BIT 2, B",		&instr_bit_2_b,		2,	8},
    [0x51] = {"BIT 2, C",		&instr_bit_2_c,		2,	8},
    [0x52] = {"BIT 2, D",		&instr_bit_2_d,		2,	8},
    [0x53] = {"BIT 2, E",		&instr_bit_2_e,		2,	8},
    [0x54] = {"BIT 2, H",		&instr_bit_2_h,		2,	8},
    [0x55] = {"BIT 2, L",		&instr_bit_2_l,		2,	8},
    [0x56] = {"BIT 2, (HL)",		&instr_bit_2_hl,	2,	16},

    // BIT 3, r : test bit 3 in register r.
    [0x5F] = {"BIT 3, A",		&instr_bit_3_a,		2,	8},
    [0x58] = {"BIT 3, B",		&instr_bit_3_b,		2,	8},
    [0x59] = {"BIT 3, C",		&instr_bit_3_c,		2,	8},
    [0x5A] = {"BIT 3, D",		&instr_bit_3_d,		2,	8},
    [0x5B] = {"BIT 3, E",		&instr_bit_3_e,		2,	8},
    [0x5C] = {"BIT 3, H",		&instr_bit_3_h,		2,	8},
    [0x5D] = {"BIT 3, L",		&instr_bit_3_l,		2,	8},
    [0x5E] = {"BIT 3, (HL)",		&instr_bit_3_hl,	2,	16},

    // BIT 4, r : test bit 4 in register r.
    [0x67] = {"BIT 4, A",		&instr_bit_4_a,		2,	8},
    [0x60] = {"BIT 4, B",		&instr_bit_4_b,		2,	8},
    [0x61] = {"BIT 4, C",		&instr_bit_4_c,		2,	8},
    [0x62] = {"BIT 4, D",		&instr_bit_4_d,		2,	8},
    [0x63] = {"BIT 4, E",		&instr_bit_4_e,		2,	8},
    [0x64] = {"BIT 4, H",		&instr_bit_4_h,		2,	8},
    [0x65] = {"BIT 4, L",		&instr_bit_4_l,		2,	8},
    [0x66] = {"BIT 4, (HL)",		&instr_bit_4_hl,	2,	16},

    // BIT 5, r : test bit 5 in register r.
    [0x6F] = {"BIT 5, A",		&instr_bit_5_a,		2,	8},
    [0x68] = {"BIT 5, B",		&instr_bit_5_b,		2,	8},
    [0x69] = {"BIT 5, C",		&instr_bit_5_c,		2,	8},
    [0x6A] = {"BIT 5, D",		&instr_bit_5_d,		2,	8},
    [0x6B] = {"BIT 5, E",		&instr_bit_5_e,		2,	8},
    [0x6C] = {"BIT 5, H",		&instr_bit_5_h,		2,	8},
    [0x6D] = {"BIT 5, L",		&instr_bit_5_l,		2,	8},
    [0x6E] = {"BIT 5, (HL)",		&instr_bit_5_hl,	2,	16},

    // BIT 6, r : test bit 6 in register r.
    [0x77] = {"BIT 6, A",		&instr_bit_6_a,		2,	8},
    [0x70] = {"BIT 6, B",		&instr_bit_6_b,		2,	8},
    [0x71] = {"BIT 6, C",		&instr_bit_6_c,		2,	8},
    [0x72] = {"BIT 6, D",		&instr_bit_6_d,		2,	8},
    [0x73] = {"BIT 6, E",		&instr_bit_6_e,		2,	8},
    [0x74] = {"BIT 6, H",		&instr_bit_6_h,		2,	8},
    [0x75] = {"BIT 6, L",		&instr_bit_6_l,		2,	8},
    [0x76] = {"BIT 6, (HL)",		&instr_bit_6_hl,	2,	16},

    // BIT 7, r : test bit 7 in register r.
    [0x7F] = {"BIT 7, A",		&instr_bit_7_a,		2,	8},
    [0x78] = {"BIT 7, B",		&instr_bit_7_b,		2,	8},
    [0x79] = {"BIT 7, C",		&instr_bit_7_c,		2,	8},
    [0x7A] = {"BIT 7, D",		&instr_bit_7_d,		2,	8},
    [0x7B] = {"BIT 7, E",		&instr_bit_7_e,		2,	8},
    [0x7C] = {"BIT 7, H",		&instr_bit_7_h,		2,	8},
    [0x7D] = {"BIT 7, L",		&instr_bit_7_l,		2,	8},
    [0x7E] = {"BIT 7, (HL)",		&instr_bit_7_hl,	2,	16},

    // SET 0, r : set bit 0 in register r.
    [0xC7] = {"SET 0, A",		&instr_set_0_a,		2,	8},
    [0xC0] = {"SET 0, B",		&instr_set_0_b,		2,	8},
    [0xC1] = {"SET 0, C",		&instr_set_0_c,		2,	8},
    [0xC2] = {"SET 0, D",		&instr_set_0_d,		2,	8},
    [0xC3] = {"SET 0, E",		&instr_set_0_e,		2,	8},
    [0xC4] = {"SET 0, H",		&instr_set_0_h,		2,	8},
    [0xC5] = {"SET 0, L",		&instr_set_0_l,		2,	8},
    [0xC6] = {"SET 0, (HL)",		&instr_set_0_hl,	2,	16},

    // SET 1, r : set bit 1 in register r.
    [0xCF] = {"SET 1, A",		&instr_set_1_a,		2,	8},
    [0xC8] = {"SET 1, B",		&instr_set_1_b,		2,	8},
    [0xC9] = {"SET 1, C",		&instr_set_1_c,		2,	8},
    [0xCA] = {"SET 1, D",		&instr_set_1_d,		2,	8},
    [0xCB] = {"SET 1, E",		&instr_set_1_e,		2,	8},
    [0xCC] = {"SET 1, H",		&instr_set_1_h,		2,	8},
    [0xCD] = {"SET 1, L",		&instr_set_1_l,		2,	8},
    [0xCE] = {"SET 1, (HL)",		&instr_set_1_hl,	2,	16},

    // SET 2, r : set bit 2 in register r.
    [0xD7] = {"SET 2, A",		&instr_set_2_a,		2,	8},
    [0xD0] = {"SET 2, B",		&instr_set_2_b,		2,	8},
    [0xD1] = {"SET 2, C",		&instr_set_2_c,		2,	8},
    [0xD2] = {"SET 2, D",		&instr_set_2_d,		2,	8},
    [0xD3] = {"SET 2, E",		&instr_set_2_e,		2,	8},
    [0xD4] = {"SET 2, H",		&instr_set_2_h,		2,	8},
    [0xD5] = {"SET 2, L",		&instr_set_2_l,		2,	8},
    [0xD6] = {"SET 2, (HL)",		&instr_set_2_hl,	2,	16},

    // SET 3, r : set bit 3 in register r.
    [0xDF] = {"SET 3, A",		&instr_set_3_a,		2,	8},
    [0xD8] = {"SET 3, B",		&instr_set_3_b,		2,	8},
    [0xD9] = {"SET 3, C",		&instr_set_3_c,		2,	8},
    [0xDA] = {"SET 3, D",		&instr_set_3_d,		2,	8},
    [0xDB] = {"SET 3, E",		&instr_set_3_e,		2,	8},
    [0xDC] = {"SET 3, H",		&instr_set_3_h,		2,	8},
    [0xDD] = {"SET 3, L",		&instr_set_3_l,		2,	8},
    [0xDE] = {"SET 3, (HL)",		&instr_set_3_hl,	2,	16},

    // SET 4, r : set bit 4 in register r.
    [0xE7] = {"SET 4, A",		&instr_set_4_a,		2,	8},
    [0xE0] = {"SET 4, B",		&instr_set_4_b,		2,	8},
    [0xE1] = {"SET 4, C",		&instr_set_4_c,		2,	8},
    [0xE2] = {"SET 4, D",		&instr_set_4_d,		2,	8},
    [0xE3] = {"SET 4, E",		&instr_set_4_e,		2,	8},
    [0xE4] = {"SET 4, H",		&instr_set_4_h,		2,	8},
    [0xE5] = {"SET 4, L",		&instr_set_4_l,		2,	8},
    [0xE6] = {"SET 4, (HL)",		&instr_set_4_hl,	2,	16},

    // SET 5, r : set bit 5 in register r.
    [0xEF] = {"SET 5, A",		&instr_set_5_a,		2,	8},
    [0xE8] = {"SET 5, B",		&instr_set_5_b,		2,	8},
    [0xE9] = {"SET 5, C",		&instr_set_5_c,		2,	8},
    [0xEA] = {"SET 5, D",		&instr_set_5_d,		2,	8},
    [0xEB] = {"SET 5, E",		&instr_set_5_e,		2,	8},
    [0xEC] = {"SET 5, H",		&instr_set_5_h,		2,	8},
    [0xED] = {"SET 5, L",		&instr_set_5_l,		2,	8},
    [0xEE] = {"SET 5, (HL)",		&instr_set_5_hl,	2,	16},

    // SET 6, r : set bit 6 in register r.
    [0xF7] = {"SET 6, A",		&instr_set_6_a,		2,	8},
    [0xF0] = {"SET 6, B",		&instr_set_6_b,		2,	8},
    [0xF1] = {"SET 6, C",		&instr_set_6_c,		2,	8},
    [0xF2] = {"SET 6, D",		&instr_set_6_d,		2,	8},
    [0xF3] = {"SET 6, E",		&instr_set_6_e,		2,	8},
    [0xF4] = {"SET 6, H",		&instr_set_6_h,		2,	8},
    [0xF5] = {"SET 6, L",		&instr_set_6_l,		2,	8},
    [0xF6] = {"SET 6, (HL)",		&instr_set_6_hl,	2,	16},

    // SET 7, r : set bit 7 in register r.
    [0xFF] = {"SET 7, A",		&instr_set_7_a,		2,	8},
    [0xF8] = {"SET 7, B",		&instr_set_7_b,		2,	8},
    [0xF9] = {"SET 7, C",		&instr_set_7_c,		2,	8},
    [0xFA] = {"SET 7, D",		&instr_set_7_d,		2,	8},
    [0xFB] = {"SET 7, E",		&instr_set_7_e,		2,	8},
    [0xFC] = {"SET 7, H",		&instr_set_7_h,		2,	8},
    [0xFD] = {"SET 7, L",		&instr_set_7_l,		2,	8},
    [0xFE] = {"SET 7, (HL)",		&instr_set_7_hl,	2,	16},

    // RES 0, r : reset bit 0 in register r.
    [0x87] = {"RES 0, A",		&instr_res_0_a,		2,	8},
    [0x80] = {"RES 0, B",		&instr_res_0_b,		2,	8},
    [0x81] = {"RES 0, C",		&instr_res_0_c,		2,	8},
    [0x82] = {"RES 0, D",		&instr_res_0_d,		2,	8},
    [0x83] = {"RES 0, E",		&instr_res_0_e,		2,	8},
    [0x84] = {"RES 0, H",		&instr_res_0_h,		2,	8},
    [0x85] = {"RES 0, L",		&instr_res_0_l,		2,	8},
    [0x86] = {"RES 0, (HL)",		&instr_res_0_hl,	2,	16},

    // RES 1, r : reset bit 1 in register r.
    [0x8F] = {"RES 1, A",		&instr_res_1_a,		2,	8},
    [0x88] = {"RES 1, B",		&instr_res_1_b,		2,	8},
    [0x89] = {"RES 1, C",		&instr_res_1_c,		2,	8},
    [0x8A] = {"RES 1, D",		&instr_res_1_d,		2,	8},
    [0x8B] = {"RES 1, E",		&instr_res_1_e,		2,	8},
    [0x8C] = {"RES 1, H",		&instr_res_1_h,		2,	8},
    [0x8D] = {"RES 1, L",		&instr_res_1_l,		2,	8},
    [0x8E] = {"RES 1, (HL)",		&instr_res_1_hl,	2,	16},

    // RES 2, r : reset bit 2 in register r.
    [0x97] = {"RES 2, A",		&instr_res_2_a,		2,	8},
    [0x90] = {"RES 2, B",		&instr_res_2_b,		2,	8},
    [0x91] = {"RES 2, C",		&instr_res_2_c,		2,	8},
    [0x92] = {"RES 2, D",		&instr_res_2_d,		2,	8},
    [0x93] = {"RES 2, E",		&instr_res_2_e,		2,	8},
    [0x94] = {"RES 2, H",		&instr_res_2_h,		2,	8},
    [0x95] = {"RES 2, L",		&instr_res_2_l,		2,	8},
    [0x96] = {"RES 2, (HL)",		&instr_res_2_hl,	2,	16},

    // RES 3, r : reset bit 3 in register r.
    [0x9F] = {"RES 3, A",		&instr_res_3_a,		2,	8},
    [0x98] = {"RES 3, B",		&instr_res_3_b,		2,	8},
    [0x99] = {"RES 3, C",		&instr_res_3_c,		2,	8},
    [0x9A] = {"RES 3, D",		&instr_res_3_d,		2,	8},
    [0x9B] = {"RES 3, E",		&instr_res_3_e,		2,	8},
    [0x9C] = {"RES 3, H",		&instr_res_3_h,		2,	8},
    [0x9D] = {"RES 3, L",		&instr_res_3_l,		2,	8},
    [0x9E] = {"RES 3, (HL)",		&instr_res_3_hl,	2,	16},

    // RES 4, r : reset bit 4 in register r.
    [0xA7] = {"RES 4, A",		&instr_res_4_a,		2,	8},
    [0xA0] = {"RES 4, B",		&instr_res_4_b,		2,	8},
    [0xA1] = {"RES 4, C",		&instr_res_4_c,		2,	8},
    [0xA2] = {"RES 4, D",		&instr_res_4_d,		2,	8},
    [0xA3] = {"RES 4, E",		&instr_res_4_e,		2,	8},
    [0xA4] = {"RES 4, H",		&instr_res_4_h,		2,	8},
    [0xA5] = {"RES 4, L",		&instr_res_4_l,		2,	8},
    [0xA6] = {"RES 4, (HL)",		&instr_res_4_hl,	2,	16},

    // RES 5, r : reset bit 5 in register r.
    [0xAF] = {"RES 5, A",		&instr_res_5_a,		2,	8},
    [0xA8] = {"RES 5, B",		&instr_res_5_b,		2,	8},
    [0xA9] = {"RES 5, C",		&instr_res_5_c,		2,	8},
    [0xAA] = {"RES 5, D",		&instr_res_5_d,		2,	8},
    [0xAB] = {"RES 5, E",		&instr_res_5_e,		2,	8},
    [0xAC] = {"RES 5, H",		&instr_res_5_h,		2,	8},
    [0xAD] = {"RES 5, L",		&instr_res_5_l,		2,	8},
    [0xAE] = {"RES 5, (HL)",		&instr_res_5_hl,	2,	16},

    // RES 6, r : reset bit 6 in register r.
    [0xB7] = {"RES 6, A",		&instr_res_6_a,		2,	8},
    [0xB0] = {"RES 6, B",		&instr_res_6_b,		2,	8},
    [0xB1] = {"RES 6, C",		&instr_res_6_c,		2,	8},
    [0xB2] = {"RES 6, D",		&instr_res_6_d,		2,	8},
    [0xB3] = {"RES 6, E",		&instr_res_6_e,		2,	8},
    [0xB4] = {"RES 6, H",		&instr_res_6_h,		2,	8},
    [0xB5] = {"RES 6, L",		&instr_res_6_l,		2,	8},
    [0xB6] = {"RES 6, (HL)",		&instr_res_6_hl,	2,	16},

    // RES 7, r : reset bit 7 in register r.
    [0xBF] = {"RES 7, A",		&instr_res_7_a,		2,	8},
    [0xB8] = {"RES 7, B",		&instr_res_7_b,		2,	8},
    [0xB9] = {"RES 7, C",		&instr_res_7_c,		2,	8},
    [0xBA] = {"RES 7, D",		&instr_res_7_d,		2,	8},
    [0xBB] = {"RES 7, E",		&instr_res_7_e,		2,	8},
    [0xBC] = {"RES 7, H",		&instr_res_7_h,		2,	8},
    [0xBD] = {"RES 7, L",		&instr_res_7_l,		2,	8},
    [0xBE] = {"RES 7, (HL)",		&instr_res_7_hl,	2,	16},

};
