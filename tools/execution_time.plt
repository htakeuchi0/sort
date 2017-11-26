# gnuplot -e "file=<入力CSVファイル名>; output=<出力EPSファイル名> excution_time.plt


set datafile separator ","
set grid

# タイトル
set title 'Execution time [ms]' font "Times-Roman, 24"

# x軸
set xlabel 'Array Size' font "Times-Roman, 16"

# y軸
set ylabel 'Time [ms]' font "Times-Roman, 16"

# 凡例の位置
set key left top

# グラフの描画
plot file using 1:2 with linespoints title "Bucket",\
	 file using 1:3 with linespoints title "Radix",\
	 file using 1:4 with linespoints title "Bubble",\
	 file using 1:5 with linespoints title "Insert",\
	 file using 1:6 with linespoints title "Selection",\
	 file using 1:7 with linespoints title "Heap",\
	 file using 1:8 with linespoints title "Quick"

# 指定ファイルに出力
set output outfile
set terminal postscript eps color "Times-Roman, 16"

# 標準出力
replot
set terminal x11
set output

# Enterキー待機
pause -1 "\nMessage: Enterキーで終了します。"
