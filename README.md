ebdata
======

This is a project for my PR Class

Developed by VS 2013 C++ Language

Step1: Load_Data
Step2: Build Hash & Filter Data with the date of verified
Step3: Generate Features
	(1) basic info
		id -> id
		gender -> enum { 'f','m','x' }
		date_of_birth ->
			a) [year A , year B] (year start from 1930 to 2012, length start from 1 to 10)
			b) Month -> histogram
			c) Month -> Season (Histogram)
		city -> histogram
		type -> [0,10]
	(2) size of trade_list
	(3) trade_date region
	(4) Gap
		Gap's statistics Feature
	(5) Date
		Date's statistics Feature
	(6) Distances between every 2 trades
		Statistics Feature(dist2,dist_global)
	(7) Distances between one trade and the trade followed
		Statistics Feature(dist2,dist_global)
Step4: Scale each of feature to [0,1]
Step5: Mark each of the feature by using a threshold classifer in training data
	select the features precision which is over 18% when it returns at least 500 positive samples.
	Why 500? I guess it may be worked.
Step6: Generate trainset from train dataset.
	20% Neg
	100% Pos
	so it can deal with overfitting problem
