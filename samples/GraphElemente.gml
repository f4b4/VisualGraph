Creator	"yFiles"
Version	"HEAD-Current"
graph
[
	hierarchic	1
	label	""
	directed	1
	node
	[
		id	0
		label	"Node_01"
		graphics
		[
			x	-19.91360092163086
			y	-86.50080108642578
			w	73.82720184326172
			h	45.97439956665039
			type	"octagon"
			fill	"#33CCCC"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Node_01"
			fontSize	12
			fontName	"Dialog"
			anchor	"c"
		]
	]
	node
	[
		id	1
		label	""
		graphics
		[
			x	-37.53919982910156
			y	238.06239318847656
			w	30.0
			h	30.0
			type	"ellipse"
			fill	"#FFFF99"
			outline	"#000000"
		]
		LabelGraphics
		[
		]
	]
	node
	[
		id	2
		label	"08/15"
		graphics
		[
			x	133.8159942626953
			y	62.98720169067383
			w	99.63200378417969
			h	45.97439956665039
			type	"roundrectangle"
			fill	"#FFCC00"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"08/15"
			fontSize	24
			fontStyle	"bold"
			fontName	"Arial"
			anchor	"c"
		]
	]
	node
	[
		id	3
		label	""
		graphics
		[
			x	143.2480010986328
			y	168.7008056640625
			w	30.0
			h	30.0
			type	"triangle"
			fill	"#999999"
			outline	"#000000"
		]
		LabelGraphics
		[
		]
	]
	node
	[
		id	4
		label	"ABC"
		graphics
		[
			x	5.628799915313721
			y	103.53119659423828
			w	78.74240112304688
			h	52.937599182128906
			type	"diamond"
			fill	"#99CC00"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"ABC"
			fontSize	12
			fontName	"Dialog"
			anchor	"c"
		]
	]
	edge
	[
		source	0
		target	2
		label	"rote Linie"
		graphics
		[
			smoothBends	1
			width	5
			style	"dashed_dotted"
			fill	"#800000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	-19.91360092163086
					y	-86.50080108642578
				]
				point
				[
					x	-17.0
					y	11.5
				]
				point
				[
					x	63.0
					y	-54.231201171875
				]
				point
				[
					x	77.38079833984375
					y	-2.188800096511841
				]
				point
				[
					x	133.8159942626953
					y	62.98720169067383
				]
			]
		]
		edgeAnchor
		[
			ySource	1.0
			yTarget	-1.0
		]
		LabelGraphics
		[
			text	"rote Linie"
			fontSize	12
			fontName	"Dialog"
			model	"six_pos"
			position	"tail"
		]
	]
	edge
	[
		source	2
		target	4
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			xSource	-1.0005648136138916
			yTarget	-1.0
		]
	]
	edge
	[
		source	4
		target	1
		graphics
		[
			smoothBends	1
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	5.628799915313721
					y	103.53119659423828
				]
				point
				[
					x	-44.59280014038086
					y	166.03280639648438
				]
				point
				[
					x	13.178400039672852
					y	176.68240356445312
				]
				point
				[
					x	-33.078399658203125
					y	197.2736053466797
				]
				point
				[
					x	-37.53919982910156
					y	238.06239318847656
				]
			]
		]
		edgeAnchor
		[
			ySource	0.9997146725654602
			yTarget	-1.0
		]
	]
	edge
	[
		source	4
		target	3
		label	"blaue Linie"
		graphics
		[
			smoothBends	1
			width	3
			style	"dashed"
			fill	"#0000FF"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	5.628799915313721
					y	103.53119659423828
				]
				point
				[
					x	76.10160064697266
					y	126.48320007324219
				]
				point
				[
					x	112.52799987792969
					y	94.46399688720703
				]
				point
				[
					x	143.2480010986328
					y	168.7008056640625
				]
			]
		]
		edgeAnchor
		[
			xSource	0.5
			ySource	0.49791666865348816
			yTarget	-1.0
		]
		LabelGraphics
		[
			text	"blaue Linie"
			fontSize	12
			fontName	"Dialog"
			model	"six_pos"
			position	"tail"
		]
	]
]
