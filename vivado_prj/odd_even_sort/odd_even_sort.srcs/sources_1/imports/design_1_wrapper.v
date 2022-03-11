//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2021.2 (lin64) Build 3367213 Tue Oct 19 02:47:39 MDT 2021
//Date        : Fri Mar 11 23:17:32 2022
//Host        : debian running 64-bit Debian GNU/Linux 11 (bullseye)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (c0_init_calib_complete_0,
    ddr4_sdram_062_act_n,
    ddr4_sdram_062_adr,
    ddr4_sdram_062_ba,
    ddr4_sdram_062_bg,
    ddr4_sdram_062_ck_c,
    ddr4_sdram_062_ck_t,
    ddr4_sdram_062_cke,
    ddr4_sdram_062_cs_n,
    ddr4_sdram_062_dm_n,
    ddr4_sdram_062_dq,
    ddr4_sdram_062_dqs_c,
    ddr4_sdram_062_dqs_t,
    ddr4_sdram_062_odt,
    ddr4_sdram_062_reset_n,
    reset,
    user_si570_sysclk_clk_n,
    user_si570_sysclk_clk_p);
  output c0_init_calib_complete_0;
  output ddr4_sdram_062_act_n;
  output [16:0]ddr4_sdram_062_adr;
  output [1:0]ddr4_sdram_062_ba;
  output ddr4_sdram_062_bg;
  output ddr4_sdram_062_ck_c;
  output ddr4_sdram_062_ck_t;
  output ddr4_sdram_062_cke;
  output ddr4_sdram_062_cs_n;
  inout [7:0]ddr4_sdram_062_dm_n;
  inout [63:0]ddr4_sdram_062_dq;
  inout [7:0]ddr4_sdram_062_dqs_c;
  inout [7:0]ddr4_sdram_062_dqs_t;
  output ddr4_sdram_062_odt;
  output ddr4_sdram_062_reset_n;
  input reset;
  input user_si570_sysclk_clk_n;
  input user_si570_sysclk_clk_p;

  wire c0_init_calib_complete_0;
  wire ddr4_sdram_062_act_n;
  wire [16:0]ddr4_sdram_062_adr;
  wire [1:0]ddr4_sdram_062_ba;
  wire ddr4_sdram_062_bg;
  wire ddr4_sdram_062_ck_c;
  wire ddr4_sdram_062_ck_t;
  wire ddr4_sdram_062_cke;
  wire ddr4_sdram_062_cs_n;
  wire [7:0]ddr4_sdram_062_dm_n;
  wire [63:0]ddr4_sdram_062_dq;
  wire [7:0]ddr4_sdram_062_dqs_c;
  wire [7:0]ddr4_sdram_062_dqs_t;
  wire ddr4_sdram_062_odt;
  wire ddr4_sdram_062_reset_n;
  wire reset;
  wire user_si570_sysclk_clk_n;
  wire user_si570_sysclk_clk_p;

  design_1 design_1_i
       (.c0_init_calib_complete_0(c0_init_calib_complete_0),
        .ddr4_sdram_062_act_n(ddr4_sdram_062_act_n),
        .ddr4_sdram_062_adr(ddr4_sdram_062_adr),
        .ddr4_sdram_062_ba(ddr4_sdram_062_ba),
        .ddr4_sdram_062_bg(ddr4_sdram_062_bg),
        .ddr4_sdram_062_ck_c(ddr4_sdram_062_ck_c),
        .ddr4_sdram_062_ck_t(ddr4_sdram_062_ck_t),
        .ddr4_sdram_062_cke(ddr4_sdram_062_cke),
        .ddr4_sdram_062_cs_n(ddr4_sdram_062_cs_n),
        .ddr4_sdram_062_dm_n(ddr4_sdram_062_dm_n),
        .ddr4_sdram_062_dq(ddr4_sdram_062_dq),
        .ddr4_sdram_062_dqs_c(ddr4_sdram_062_dqs_c),
        .ddr4_sdram_062_dqs_t(ddr4_sdram_062_dqs_t),
        .ddr4_sdram_062_odt(ddr4_sdram_062_odt),
        .ddr4_sdram_062_reset_n(ddr4_sdram_062_reset_n),
        .reset(reset),
        .user_si570_sysclk_clk_n(user_si570_sysclk_clk_n),
        .user_si570_sysclk_clk_p(user_si570_sysclk_clk_p));
endmodule
