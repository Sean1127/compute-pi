reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance'
set term png enhanced font 'Verdana,10'
set output 'time.png'

plot [:][:]'time.txt' using 
