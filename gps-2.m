#用于定义X射线源 包括 能谱、角分布、
#定义一个圆形面源

/gps/particle gamma
/gps/pos/type Plane
/gps/pos/shape Circle
/gps/pos/centre 0. 0. -3.5 cm
/gps/pos/radius 2. mm

#位置

#能谱

/gps/ene/type Arb
/gps/hist/file ./spec/energy.dat
/gps/hist/inter Lin

#角度
/gps/ang/type user
/gps/hist/type theta
/gps/hist/point	0.000872665	4
/gps/hist/point	0.002617994	39
/gps/hist/point	0.004363323	47
/gps/hist/point	0.006108652	72
/gps/hist/point	0.007853982	92
/gps/hist/point	0.009599311	89
/gps/hist/point	0.01134464	121
/gps/hist/point	0.013089969	137
/gps/hist/point	0.014835299	175
/gps/hist/point	0.016580628	187
/gps/hist/point	0.018325957	190
/gps/hist/point	0.020071286	227
/gps/hist/point	0.021816616	249
/gps/hist/point	0.023561945	265
/gps/hist/point	0.025307274	261
/gps/hist/point	0.027052603	299
/gps/hist/point	0.028797933	331
/gps/hist/point	0.030543262	319
/gps/hist/point	0.032288591	367
/gps/hist/point	0.03403392	366
/gps/hist/point	0.03577925	381
/gps/hist/point	0.037524579	455
/gps/hist/point	0.039269908	421
/gps/hist/point	0.041015237	473
/gps/hist/point	0.042760567	507
/gps/hist/point	0.044505896	521
/gps/hist/point	0.046251225	490
/gps/hist/point	0.047996554	506
/gps/hist/point	0.049741884	528
/gps/hist/point	0.051487213	545
/gps/hist/point	0.053232542	587
/gps/hist/point	0.054977871	576
/gps/hist/point	0.056723201	600
/gps/hist/point	0.05846853	670
/gps/hist/point	0.060213859	643
/gps/hist/point	0.061959188	703
/gps/hist/point	0.063704518	701
/gps/hist/point	0.065449847	714
/gps/hist/point	0.067195176	705
/gps/hist/point	0.068940505	723
/gps/hist/point	0.070685835	791
/gps/hist/point	0.072431164	769
/gps/hist/point	0.074176493	805
/gps/hist/point	0.075921822	864
/gps/hist/point	0.077667152	787
/gps/hist/point	0.079412481	905
/gps/hist/inter Lin

#运行数
/run/printProgress 100
#/run/beamOn 50000000
