set terminal x11  # 或者 qt，根据你的安装情况
set title "Comparison of Numerical Solution and Exact Solution"
set xlabel "x"
set ylabel "u(x)"
set grid

plot "u_k.data" using 1:2 with lines title "Initial Condition", \
     "u_kp1.data" using 1:2 with lines title "Numerical Solution (Jacobi)", \
     "u_ref.data" using 1:2 with lines title "Exact Solution", \
     "u_kp1_gs.data" using 1:2 with lines title "Numerical Solution (Gauss-Seidel)"

pause -1 "Press Enter to exit"
