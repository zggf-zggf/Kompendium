for((i = 0; i < 1000; i++)); do
	echo $i
	./gen $i 5 5 10 > inc.in
	./brut < inc.in > out1.out
	./prog < inc.in > out2.out
	diff out1.out out2.out || break;
done;
