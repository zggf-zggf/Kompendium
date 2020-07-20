for((i=0; i<1000; i++)); do
	echo $i
	./gen 50 $i > in1.in
	./prog < in1.in > out1
	time ./brut < in1.in > out2
	diff out1 out2 || break
done
cat in1.in
