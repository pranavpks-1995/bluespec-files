/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Fri Mar 16 16:00:53 IST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "files.h"


/* String declarations */
static std::string const __str_literal_3("cannot open %s", 14u);
static std::string const __str_literal_4("cnt = %0d\n", 10u);
static std::string const __str_literal_1("dump_file1.dat", 14u);
static std::string const __str_literal_2("w", 1u);


/* Constructor */
MOD_files::MOD_files(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cnt(simHdl, "cnt", this, 32u, 0u, (tUInt8)0u),
    INST_done(simHdl, "done", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_fh(simHdl, "fh", this, 32u, 0u, (tUInt8)0u),
    INST_fmcd(simHdl, "fmcd", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u),
    DEF_TASK_fopen___d3(2863311530u)
{
  symbol_count = 14u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_files::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h171", SYM_DEF, &DEF_b__h171, 32u);
  init_symbol(&symbols[1u], "CAN_FIRE_RL_dump", SYM_DEF, &DEF_CAN_FIRE_RL_dump, 1u);
  init_symbol(&symbols[2u], "CAN_FIRE_RL_ends", SYM_DEF, &DEF_CAN_FIRE_RL_ends, 1u);
  init_symbol(&symbols[3u], "CAN_FIRE_RL_open", SYM_DEF, &DEF_CAN_FIRE_RL_open, 1u);
  init_symbol(&symbols[4u], "cnt", SYM_MODULE, &INST_cnt);
  init_symbol(&symbols[5u], "done", SYM_MODULE, &INST_done);
  init_symbol(&symbols[6u], "fh", SYM_MODULE, &INST_fh);
  init_symbol(&symbols[7u], "fmcd", SYM_MODULE, &INST_fmcd);
  init_symbol(&symbols[8u], "RL_dump", SYM_RULE);
  init_symbol(&symbols[9u], "RL_ends", SYM_RULE);
  init_symbol(&symbols[10u], "RL_open", SYM_RULE);
  init_symbol(&symbols[11u], "WILL_FIRE_RL_dump", SYM_DEF, &DEF_WILL_FIRE_RL_dump, 1u);
  init_symbol(&symbols[12u], "WILL_FIRE_RL_ends", SYM_DEF, &DEF_WILL_FIRE_RL_ends, 1u);
  init_symbol(&symbols[13u], "WILL_FIRE_RL_open", SYM_DEF, &DEF_WILL_FIRE_RL_open, 1u);
}


/* Rule actions */

void MOD_files::RL_open()
{
  tUInt8 DEF_TASK_fopen_EQ_0___d4;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_TASK_fopen___d3 = dollar_fopen("s,s", &__str_literal_1, &__str_literal_2);
  DEF_TASK_fopen_EQ_0___d4 = DEF_TASK_fopen___d3 == 0u;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_TASK_fopen_EQ_0___d4)
      dollar_display(sim_hdl, this, "s,s", &__str_literal_3, &__str_literal_1);
    if (DEF_TASK_fopen_EQ_0___d4)
      dollar_finish(sim_hdl, "32", 0u);
  }
  INST_cnt.METH_write(1u);
  INST_fh.METH_write(DEF_TASK_fopen___d3);
}

void MOD_files::RL_dump()
{
  tUInt32 DEF_cnt_PLUS_1___d9;
  tUInt32 DEF_signed_cnt___d8;
  DEF_b__h171 = INST_cnt.METH_read();
  DEF_signed_cnt___d8 = DEF_b__h171;
  DEF_fh___d7 = INST_fh.METH_read();
  DEF_cnt_PLUS_1___d9 = DEF_b__h171 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_fwrite(sim_hdl, this, "32,s,-32", DEF_fh___d7, &__str_literal_4, DEF_signed_cnt___d8);
  INST_cnt.METH_write(DEF_cnt_PLUS_1___d9);
  INST_done.METH_write((tUInt8)1u);
}

void MOD_files::RL_ends()
{
  DEF_fh___d7 = INST_fh.METH_read();
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_fclose("32", DEF_fh___d7);
    dollar_finish(sim_hdl, "32", 0u);
  }
}


/* Methods */


/* Reset routines */

void MOD_files::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_fmcd.reset_RST(ARG_rst_in);
  INST_fh.reset_RST(ARG_rst_in);
  INST_done.reset_RST(ARG_rst_in);
  INST_cnt.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_files::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_files::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cnt.dump_state(indent + 2u);
  INST_done.dump_state(indent + 2u);
  INST_fh.dump_state(indent + 2u);
  INST_fmcd.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_files::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 14u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_dump", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_ends", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_open", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "TASK_fopen___d3", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_dump", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_ends", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_open", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h171", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "fh___d7", 32u);
  num = INST_cnt.dump_VCD_defs(num);
  num = INST_done.dump_VCD_defs(num);
  num = INST_fh.dump_VCD_defs(num);
  num = INST_fmcd.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_files::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_files &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_files::vcd_defs(tVCDDumpType dt, MOD_files &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.DEF_CAN_FIRE_RL_dump) != DEF_CAN_FIRE_RL_dump)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_dump, 1u);
	backing.DEF_CAN_FIRE_RL_dump = DEF_CAN_FIRE_RL_dump;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_ends) != DEF_CAN_FIRE_RL_ends)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_ends, 1u);
	backing.DEF_CAN_FIRE_RL_ends = DEF_CAN_FIRE_RL_ends;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_open) != DEF_CAN_FIRE_RL_open)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_open, 1u);
	backing.DEF_CAN_FIRE_RL_open = DEF_CAN_FIRE_RL_open;
      }
      ++num;
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_TASK_fopen___d3) != DEF_TASK_fopen___d3)
      {
	vcd_write_val(sim_hdl, num, DEF_TASK_fopen___d3, 32u);
	backing.DEF_TASK_fopen___d3 = DEF_TASK_fopen___d3;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_dump) != DEF_WILL_FIRE_RL_dump)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_dump, 1u);
	backing.DEF_WILL_FIRE_RL_dump = DEF_WILL_FIRE_RL_dump;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_ends) != DEF_WILL_FIRE_RL_ends)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_ends, 1u);
	backing.DEF_WILL_FIRE_RL_ends = DEF_WILL_FIRE_RL_ends;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_open) != DEF_WILL_FIRE_RL_open)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_open, 1u);
	backing.DEF_WILL_FIRE_RL_open = DEF_WILL_FIRE_RL_open;
      }
      ++num;
      if ((backing.DEF_b__h171) != DEF_b__h171)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h171, 32u);
	backing.DEF_b__h171 = DEF_b__h171;
      }
      ++num;
      if ((backing.DEF_fh___d7) != DEF_fh___d7)
      {
	vcd_write_val(sim_hdl, num, DEF_fh___d7, 32u);
	backing.DEF_fh___d7 = DEF_fh___d7;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_dump, 1u);
      backing.DEF_CAN_FIRE_RL_dump = DEF_CAN_FIRE_RL_dump;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_ends, 1u);
      backing.DEF_CAN_FIRE_RL_ends = DEF_CAN_FIRE_RL_ends;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_open, 1u);
      backing.DEF_CAN_FIRE_RL_open = DEF_CAN_FIRE_RL_open;
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_TASK_fopen___d3, 32u);
      backing.DEF_TASK_fopen___d3 = DEF_TASK_fopen___d3;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_dump, 1u);
      backing.DEF_WILL_FIRE_RL_dump = DEF_WILL_FIRE_RL_dump;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_ends, 1u);
      backing.DEF_WILL_FIRE_RL_ends = DEF_WILL_FIRE_RL_ends;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_open, 1u);
      backing.DEF_WILL_FIRE_RL_open = DEF_WILL_FIRE_RL_open;
      vcd_write_val(sim_hdl, num++, DEF_b__h171, 32u);
      backing.DEF_b__h171 = DEF_b__h171;
      vcd_write_val(sim_hdl, num++, DEF_fh___d7, 32u);
      backing.DEF_fh___d7 = DEF_fh___d7;
    }
}

void MOD_files::vcd_prims(tVCDDumpType dt, MOD_files &backing)
{
  INST_cnt.dump_VCD(dt, backing.INST_cnt);
  INST_done.dump_VCD(dt, backing.INST_done);
  INST_fh.dump_VCD(dt, backing.INST_fh);
  INST_fmcd.dump_VCD(dt, backing.INST_fmcd);
}
