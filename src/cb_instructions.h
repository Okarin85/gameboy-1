#ifndef CB_INSTRUCTIONS_H_
# define CB_INSTRUCTIONS_H_

# define NB_CB_INSTRUCTIONS	0xFF
# define MAX_CB_INSTRUCTION	0xFF

extern const t_instruction	g_cb_instructions[NB_CB_INSTRUCTIONS + 1];

typedef struct s_gameboy	t_gameboy;

void	cb_instr_swap_a_a(t_gameboy *gameboy);
void	cb_instr_swap_a_b(t_gameboy *gameboy);
void	cb_instr_swap_a_c(t_gameboy *gameboy);
void	cb_instr_swap_a_d(t_gameboy *gameboy);
void	cb_instr_swap_a_e(t_gameboy *gameboy);
void	cb_instr_swap_a_h(t_gameboy *gameboy);
void	cb_instr_swap_a_l(t_gameboy *gameboy);
void	cb_instr_swap_a_hl(t_gameboy *gameboy);
void	cb_instr_rlc_a(t_gameboy *gameboy);
void	cb_instr_rlc_b(t_gameboy *gameboy);
void	cb_instr_rlc_c(t_gameboy *gameboy);
void	cb_instr_rlc_d(t_gameboy *gameboy);
void	cb_instr_rlc_e(t_gameboy *gameboy);
void	cb_instr_rlc_h(t_gameboy *gameboy);
void	cb_instr_rlc_l(t_gameboy *gameboy);
void	cb_instr_rlc_hl(t_gameboy *gameboy);
void	cb_instr_rl_a(t_gameboy *gameboy);
void	cb_instr_rl_b(t_gameboy *gameboy);
void	cb_instr_rl_c(t_gameboy *gameboy);
void	cb_instr_rl_d(t_gameboy *gameboy);
void	cb_instr_rl_e(t_gameboy *gameboy);
void	cb_instr_rl_h(t_gameboy *gameboy);
void	cb_instr_rl_l(t_gameboy *gameboy);
void	cb_instr_rl_hl(t_gameboy *gameboy);
void	cb_instr_rrc_a(t_gameboy *gameboy);
void	cb_instr_rrc_b(t_gameboy *gameboy);
void	cb_instr_rrc_c(t_gameboy *gameboy);
void	cb_instr_rrc_d(t_gameboy *gameboy);
void	cb_instr_rrc_e(t_gameboy *gameboy);
void	cb_instr_rrc_h(t_gameboy *gameboy);
void	cb_instr_rrc_l(t_gameboy *gameboy);
void	cb_instr_rrc_hl(t_gameboy *gameboy);
void	cb_instr_rr_a(t_gameboy *gameboy);
void	cb_instr_rr_b(t_gameboy *gameboy);
void	cb_instr_rr_c(t_gameboy *gameboy);
void	cb_instr_rr_d(t_gameboy *gameboy);
void	cb_instr_rr_e(t_gameboy *gameboy);
void	cb_instr_rr_h(t_gameboy *gameboy);
void	cb_instr_rr_l(t_gameboy *gameboy);
void	cb_instr_rr_hl(t_gameboy *gameboy);
void	cb_instr_sla_a(t_gameboy *gameboy);
void	cb_instr_sla_b(t_gameboy *gameboy);
void	cb_instr_sla_c(t_gameboy *gameboy);
void	cb_instr_sla_d(t_gameboy *gameboy);
void	cb_instr_sla_e(t_gameboy *gameboy);
void	cb_instr_sla_h(t_gameboy *gameboy);
void	cb_instr_sla_l(t_gameboy *gameboy);
void	cb_instr_sla_hl(t_gameboy *gameboy);
void	cb_instr_sra_a(t_gameboy *gameboy);
void	cb_instr_sra_b(t_gameboy *gameboy);
void	cb_instr_sra_c(t_gameboy *gameboy);
void	cb_instr_sra_d(t_gameboy *gameboy);
void	cb_instr_sra_e(t_gameboy *gameboy);
void	cb_instr_sra_h(t_gameboy *gameboy);
void	cb_instr_sra_l(t_gameboy *gameboy);
void	cb_instr_sra_hl(t_gameboy *gameboy);
void	cb_instr_srl_a(t_gameboy *gameboy);
void	cb_instr_srl_b(t_gameboy *gameboy);
void	cb_instr_srl_c(t_gameboy *gameboy);
void	cb_instr_srl_d(t_gameboy *gameboy);
void	cb_instr_srl_e(t_gameboy *gameboy);
void	cb_instr_srl_h(t_gameboy *gameboy);
void	cb_instr_srl_l(t_gameboy *gameboy);
void	cb_instr_srl_hl(t_gameboy *gameboy);
void	cb_instr_bit_0_a(t_gameboy *gameboy);
void	cb_instr_bit_0_b(t_gameboy *gameboy);
void	cb_instr_bit_0_c(t_gameboy *gameboy);
void	cb_instr_bit_0_d(t_gameboy *gameboy);
void	cb_instr_bit_0_e(t_gameboy *gameboy);
void	cb_instr_bit_0_h(t_gameboy *gameboy);
void	cb_instr_bit_0_l(t_gameboy *gameboy);
void	cb_instr_bit_0_hl(t_gameboy *gameboy);
void	cb_instr_bit_1_a(t_gameboy *gameboy);
void	cb_instr_bit_1_b(t_gameboy *gameboy);
void	cb_instr_bit_1_c(t_gameboy *gameboy);
void	cb_instr_bit_1_d(t_gameboy *gameboy);
void	cb_instr_bit_1_e(t_gameboy *gameboy);
void	cb_instr_bit_1_h(t_gameboy *gameboy);
void	cb_instr_bit_1_l(t_gameboy *gameboy);
void	cb_instr_bit_1_hl(t_gameboy *gameboy);
void	cb_instr_bit_2_a(t_gameboy *gameboy);
void	cb_instr_bit_2_b(t_gameboy *gameboy);
void	cb_instr_bit_2_c(t_gameboy *gameboy);
void	cb_instr_bit_2_d(t_gameboy *gameboy);
void	cb_instr_bit_2_e(t_gameboy *gameboy);
void	cb_instr_bit_2_h(t_gameboy *gameboy);
void	cb_instr_bit_2_l(t_gameboy *gameboy);
void	cb_instr_bit_2_hl(t_gameboy *gameboy);
void	cb_instr_bit_3_a(t_gameboy *gameboy);
void	cb_instr_bit_3_b(t_gameboy *gameboy);
void	cb_instr_bit_3_c(t_gameboy *gameboy);
void	cb_instr_bit_3_d(t_gameboy *gameboy);
void	cb_instr_bit_3_e(t_gameboy *gameboy);
void	cb_instr_bit_3_h(t_gameboy *gameboy);
void	cb_instr_bit_3_l(t_gameboy *gameboy);
void	cb_instr_bit_3_hl(t_gameboy *gameboy);
void	cb_instr_bit_4_a(t_gameboy *gameboy);
void	cb_instr_bit_4_b(t_gameboy *gameboy);
void	cb_instr_bit_4_c(t_gameboy *gameboy);
void	cb_instr_bit_4_d(t_gameboy *gameboy);
void	cb_instr_bit_4_e(t_gameboy *gameboy);
void	cb_instr_bit_4_h(t_gameboy *gameboy);
void	cb_instr_bit_4_l(t_gameboy *gameboy);
void	cb_instr_bit_4_hl(t_gameboy *gameboy);
void	cb_instr_bit_5_a(t_gameboy *gameboy);
void	cb_instr_bit_5_b(t_gameboy *gameboy);
void	cb_instr_bit_5_c(t_gameboy *gameboy);
void	cb_instr_bit_5_d(t_gameboy *gameboy);
void	cb_instr_bit_5_e(t_gameboy *gameboy);
void	cb_instr_bit_5_h(t_gameboy *gameboy);
void	cb_instr_bit_5_l(t_gameboy *gameboy);
void	cb_instr_bit_5_hl(t_gameboy *gameboy);
void	cb_instr_bit_6_a(t_gameboy *gameboy);
void	cb_instr_bit_6_b(t_gameboy *gameboy);
void	cb_instr_bit_6_c(t_gameboy *gameboy);
void	cb_instr_bit_6_d(t_gameboy *gameboy);
void	cb_instr_bit_6_e(t_gameboy *gameboy);
void	cb_instr_bit_6_h(t_gameboy *gameboy);
void	cb_instr_bit_6_l(t_gameboy *gameboy);
void	cb_instr_bit_6_hl(t_gameboy *gameboy);
void	cb_instr_bit_7_a(t_gameboy *gameboy);
void	cb_instr_bit_7_b(t_gameboy *gameboy);
void	cb_instr_bit_7_c(t_gameboy *gameboy);
void	cb_instr_bit_7_d(t_gameboy *gameboy);
void	cb_instr_bit_7_e(t_gameboy *gameboy);
void	cb_instr_bit_7_h(t_gameboy *gameboy);
void	cb_instr_bit_7_l(t_gameboy *gameboy);
void	cb_instr_bit_7_hl(t_gameboy *gameboy);
void	cb_instr_set_0_a(t_gameboy *gameboy);
void	cb_instr_set_0_b(t_gameboy *gameboy);
void	cb_instr_set_0_c(t_gameboy *gameboy);
void	cb_instr_set_0_d(t_gameboy *gameboy);
void	cb_instr_set_0_e(t_gameboy *gameboy);
void	cb_instr_set_0_h(t_gameboy *gameboy);
void	cb_instr_set_0_l(t_gameboy *gameboy);
void	cb_instr_set_0_hl(t_gameboy *gameboy);
void	cb_instr_set_1_a(t_gameboy *gameboy);
void	cb_instr_set_1_b(t_gameboy *gameboy);
void	cb_instr_set_1_c(t_gameboy *gameboy);
void	cb_instr_set_1_d(t_gameboy *gameboy);
void	cb_instr_set_1_e(t_gameboy *gameboy);
void	cb_instr_set_1_h(t_gameboy *gameboy);
void	cb_instr_set_1_l(t_gameboy *gameboy);
void	cb_instr_set_1_hl(t_gameboy *gameboy);
void	cb_instr_set_2_a(t_gameboy *gameboy);
void	cb_instr_set_2_b(t_gameboy *gameboy);
void	cb_instr_set_2_c(t_gameboy *gameboy);
void	cb_instr_set_2_d(t_gameboy *gameboy);
void	cb_instr_set_2_e(t_gameboy *gameboy);
void	cb_instr_set_2_h(t_gameboy *gameboy);
void	cb_instr_set_2_l(t_gameboy *gameboy);
void	cb_instr_set_2_hl(t_gameboy *gameboy);
void	cb_instr_set_3_a(t_gameboy *gameboy);
void	cb_instr_set_3_b(t_gameboy *gameboy);
void	cb_instr_set_3_c(t_gameboy *gameboy);
void	cb_instr_set_3_d(t_gameboy *gameboy);
void	cb_instr_set_3_e(t_gameboy *gameboy);
void	cb_instr_set_3_h(t_gameboy *gameboy);
void	cb_instr_set_3_l(t_gameboy *gameboy);
void	cb_instr_set_3_hl(t_gameboy *gameboy);
void	cb_instr_set_4_a(t_gameboy *gameboy);
void	cb_instr_set_4_b(t_gameboy *gameboy);
void	cb_instr_set_4_c(t_gameboy *gameboy);
void	cb_instr_set_4_d(t_gameboy *gameboy);
void	cb_instr_set_4_e(t_gameboy *gameboy);
void	cb_instr_set_4_h(t_gameboy *gameboy);
void	cb_instr_set_4_l(t_gameboy *gameboy);
void	cb_instr_set_4_hl(t_gameboy *gameboy);
void	cb_instr_set_5_a(t_gameboy *gameboy);
void	cb_instr_set_5_b(t_gameboy *gameboy);
void	cb_instr_set_5_c(t_gameboy *gameboy);
void	cb_instr_set_5_d(t_gameboy *gameboy);
void	cb_instr_set_5_e(t_gameboy *gameboy);
void	cb_instr_set_5_h(t_gameboy *gameboy);
void	cb_instr_set_5_l(t_gameboy *gameboy);
void	cb_instr_set_5_hl(t_gameboy *gameboy);
void	cb_instr_set_6_a(t_gameboy *gameboy);
void	cb_instr_set_6_b(t_gameboy *gameboy);
void	cb_instr_set_6_c(t_gameboy *gameboy);
void	cb_instr_set_6_d(t_gameboy *gameboy);
void	cb_instr_set_6_e(t_gameboy *gameboy);
void	cb_instr_set_6_h(t_gameboy *gameboy);
void	cb_instr_set_6_l(t_gameboy *gameboy);
void	cb_instr_set_6_hl(t_gameboy *gameboy);
void	cb_instr_set_7_a(t_gameboy *gameboy);
void	cb_instr_set_7_b(t_gameboy *gameboy);
void	cb_instr_set_7_c(t_gameboy *gameboy);
void	cb_instr_set_7_d(t_gameboy *gameboy);
void	cb_instr_set_7_e(t_gameboy *gameboy);
void	cb_instr_set_7_h(t_gameboy *gameboy);
void	cb_instr_set_7_l(t_gameboy *gameboy);
void	cb_instr_set_7_hl(t_gameboy *gameboy);
void	cb_instr_res_0_a(t_gameboy *gameboy);
void	cb_instr_res_0_b(t_gameboy *gameboy);
void	cb_instr_res_0_c(t_gameboy *gameboy);
void	cb_instr_res_0_d(t_gameboy *gameboy);
void	cb_instr_res_0_e(t_gameboy *gameboy);
void	cb_instr_res_0_h(t_gameboy *gameboy);
void	cb_instr_res_0_l(t_gameboy *gameboy);
void	cb_instr_res_0_hl(t_gameboy *gameboy);
void	cb_instr_res_1_a(t_gameboy *gameboy);
void	cb_instr_res_1_b(t_gameboy *gameboy);
void	cb_instr_res_1_c(t_gameboy *gameboy);
void	cb_instr_res_1_d(t_gameboy *gameboy);
void	cb_instr_res_1_e(t_gameboy *gameboy);
void	cb_instr_res_1_h(t_gameboy *gameboy);
void	cb_instr_res_1_l(t_gameboy *gameboy);
void	cb_instr_res_1_hl(t_gameboy *gameboy);
void	cb_instr_res_2_a(t_gameboy *gameboy);
void	cb_instr_res_2_b(t_gameboy *gameboy);
void	cb_instr_res_2_c(t_gameboy *gameboy);
void	cb_instr_res_2_d(t_gameboy *gameboy);
void	cb_instr_res_2_e(t_gameboy *gameboy);
void	cb_instr_res_2_h(t_gameboy *gameboy);
void	cb_instr_res_2_l(t_gameboy *gameboy);
void	cb_instr_res_2_hl(t_gameboy *gameboy);
void	cb_instr_res_3_a(t_gameboy *gameboy);
void	cb_instr_res_3_b(t_gameboy *gameboy);
void	cb_instr_res_3_c(t_gameboy *gameboy);
void	cb_instr_res_3_d(t_gameboy *gameboy);
void	cb_instr_res_3_e(t_gameboy *gameboy);
void	cb_instr_res_3_h(t_gameboy *gameboy);
void	cb_instr_res_3_l(t_gameboy *gameboy);
void	cb_instr_res_3_hl(t_gameboy *gameboy);
void	cb_instr_res_4_a(t_gameboy *gameboy);
void	cb_instr_res_4_b(t_gameboy *gameboy);
void	cb_instr_res_4_c(t_gameboy *gameboy);
void	cb_instr_res_4_d(t_gameboy *gameboy);
void	cb_instr_res_4_e(t_gameboy *gameboy);
void	cb_instr_res_4_h(t_gameboy *gameboy);
void	cb_instr_res_4_l(t_gameboy *gameboy);
void	cb_instr_res_4_hl(t_gameboy *gameboy);
void	cb_instr_res_5_a(t_gameboy *gameboy);
void	cb_instr_res_5_b(t_gameboy *gameboy);
void	cb_instr_res_5_c(t_gameboy *gameboy);
void	cb_instr_res_5_d(t_gameboy *gameboy);
void	cb_instr_res_5_e(t_gameboy *gameboy);
void	cb_instr_res_5_h(t_gameboy *gameboy);
void	cb_instr_res_5_l(t_gameboy *gameboy);
void	cb_instr_res_5_hl(t_gameboy *gameboy);
void	cb_instr_res_6_a(t_gameboy *gameboy);
void	cb_instr_res_6_b(t_gameboy *gameboy);
void	cb_instr_res_6_c(t_gameboy *gameboy);
void	cb_instr_res_6_d(t_gameboy *gameboy);
void	cb_instr_res_6_e(t_gameboy *gameboy);
void	cb_instr_res_6_h(t_gameboy *gameboy);
void	cb_instr_res_6_l(t_gameboy *gameboy);
void	cb_instr_res_6_hl(t_gameboy *gameboy);
void	cb_instr_res_7_a(t_gameboy *gameboy);
void	cb_instr_res_7_b(t_gameboy *gameboy);
void	cb_instr_res_7_c(t_gameboy *gameboy);
void	cb_instr_res_7_d(t_gameboy *gameboy);
void	cb_instr_res_7_e(t_gameboy *gameboy);
void	cb_instr_res_7_h(t_gameboy *gameboy);
void	cb_instr_res_7_l(t_gameboy *gameboy);
void	cb_instr_res_7_hl(t_gameboy *gameboy);

#endif /* !CB_INSTRUCTIONS_H_ */