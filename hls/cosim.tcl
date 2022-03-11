set target cosim
set i 1
while {[file exists [set prj_dir ${target}_$i]]} {incr i}

open_project $prj_dir -reset
open_solution [set solution_dir solution1] -reset
set_part {xczu7ev-ffvc1156-2-e}
set_top odd_even_sort_top
create_clock -period 300MHz

set common_cflags {}
lappend common_cflags {-O3}
lappend common_cflags {-std=c++14}
lappend common_cflags {-Wall}
lappend common_cflags {-Wextra}
lappend common_cflags {-Wno-unused-label}
lappend common_cflags {-DD_MYARR_SIZE=100}
lappend common_cflags {-DD_MYARR_TYPE=int}
lappend common_cflags {-DD_MYARR_M_AXI_INTERFACE}

set cflags $common_cflags
add_files {../src/odd_even_sort/odd_even_sort_top.cpp} -cflags $cflags

set cflags $common_cflags
lappend cflags {-I../src/pcg/}
lappend cflags {-DD_DEBUG}
lappend cflags {-DD_FIXED_SEED=986122344}
add_files -tb {../src/odd_even_sort/tb.cpp} -cflags $cflags

config_interface -m_axi_addr64=false
csynth_design
cosim_design -O
puts {---------------------------------------------}
puts " PRJ_DIR: $prj_dir"
puts {---------------------------------------------}
exit
