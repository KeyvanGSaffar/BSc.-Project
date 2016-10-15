	<link rel="stylesheet" type="text/css" href="bootstrap.min.css" />
<style type="text/css">

body{
		background:
		radial-gradient(black 15%, transparent 16%) 0 0,
		radial-gradient(black 15%, transparent 16%) 8px 8px,
		radial-gradient(rgba(255,255,255,.1) 15%, transparent 20%) 0 1px,
		radial-gradient(rgba(255,255,255,.1) 15%, transparent 20%) 8px 9px;
		background-color:#282828;
		background-size:16px 16px;
	}
.container{
	width: 75%;
}
li{
	margin-left: -20px;
	margin-right: -60px;
	padding-right: 10px;
	font-family: b nazanin;
	font-size: 15px;
}
.active{
	color: #ffffff;
	text-shadow: 0 -1px 0 rgba(0, 0, 0, 0.2);
	background-color: #0088cc;
	line-height: 45px;
	padding-right: -10px;
 	
}
.nav-header{
	font-size: 20px;
	color: #0088cc;
	padding-bottom: 25px;
	padding-right: 20px;
	font-family: B Titr Bold;
}
.mainContainer{
	width: 75%;
 	opacity: 0.8;	
    filter: alpha(opacity=80); /* For IE8 and earlier */
    height: 100%;
    text-align: center;
	margin: auto;
	padding-top:50px; 
	font-family: b nazanin;
	font-size: 15px;

}
.mainContainer:hover {
    opacity: 1;
    filter: alpha(opacity=100); /* For IE8 and earlier */
}

</style>
<script>
function changeConfirm(frm){
	 if(!confirm('آیا واقعا مایل به تغییر تنظیمات شبکه هستید؟')) return;
	 frm.submit();
}
function changePass(frm){
		if(document.getElementById('pw').value!=document.getElementById('pw2').value) {
			alert('خطا!پسورد ها یکسان نیستند!');
			return;
		}
	 frm.submit();
}
function AllSW(st) {
	for(i=0;i<document.form1.length;i++) {
		if(document.form1.elements[i].type=="checkbox"){
			document.form1.elements[i].checked=st; 
		}
	}
	document.form1.submit();
}

</script>

</head>
<body>
	<div class="header navbar navbar-inverse navbar-fixed-top "  role="navigation">
	    <div class="container">
			<div class="navbar-header">
	          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
	            <span class="icon-bar"></span>
	            <span class="icon-bar"></span>
	            <span class="icon-bar"></span>
	          </button>
	          <a class="navbar-brand label-success" style="color:#fff;font-size: 10pt;font-weight: bold;direction:rtl;padding-bottom:40px;" href="#">
	          	توسعه وب سرور بر روی Embedded System مبتنی بر پردازنده ARM
	          </a>
	        </div>
	        <div class="">
	          	<div class="navbar-brand navbar-right navbar-collapse collapse" style="color:#fff;font-size: 12pt;font-weight: bold;min-width:500px;" >
					سید فرشاد کاظمی و کیوان قارونی صفار
	         	 </div>
        	</div><!--/.navbar-collapse -->
        </div>
	</div>
    <div class="fade mainContainer delay15">
	    <div class="col-md-3 pull-right" style="padding-top:10px;text-align:right;direction:rtl;">
	      <div class="well sidebar-nav">
	        <ul class="nav nav-list">
	          <li class="nav-header">صفحات پروژه</li>
