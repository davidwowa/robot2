TODO 
http://raspi.tv/2013/controlled-shutdown-duration-test-of-pi-model-a-with-2-cell-lipo

wrong solution
for id in core sdram_c sdram_i sdram_p
do
    echo -e "$id:\t$(vcgencmd measure_volts $id)"
done