set targets {synth sim cosim export}
foreach target $targets {
  foreach dir [glob -nocomplain -types d -- ${target}_*] {
    if {[catch {file delete -force -- $dir}]} {
      puts "deleting dir $dir ... FAIL";
    } else {
      puts "deleting dir $dir ... OK";
    }
  }
}
