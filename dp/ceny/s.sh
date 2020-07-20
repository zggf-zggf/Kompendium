for((i = 0; i < 1000; i++))
do
echo $i
./gen 10 5 $i > in1.in
./prog < in1.in > out1.out
./brut < in1.in > out2.out
diff out1.out out2.out || break
done
cat in1.in
