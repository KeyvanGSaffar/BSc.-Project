t <!DOCTYPE html>
t <html lang="en">
t <head>
t 	<meta charset="UTF-8">
t 	<title>زبان سيستم</title>
t 	<link rel="stylesheet" type="text/css" href="bootstrap.min.css" />
i header.inc
t 	          <li ><a href="index.htm">صفحه اصلی</a></li>
t 	          <li><a href="leds.cgi">مدیریت LED</a></li>
t 	          <li><a href="network.cgi">تنظمیات شبکه</a></li>
t 	          <li><a href="system.cgi">رمز عبور</a></li>
t 	          <li><a href="tcp.cgi">وضعیت پورتها</a></li>
t 	          <li class="active">زبان</li>
t 	          <li><a href="buttons.cgi">وضعیت سوئیچ ها	</a></li>     
t 	          <li><a href="lcd.cgi">نمایش روی LCD</a></li>
t 	          <li><a href="temp.cgi">مشاهده دما</a></li>              
t 	        </ul>
t 	      </div><!--/.well -->
t 	    </div><!--/span-->
t 	    <div class="col-md-9 pull-left well" style="margin-top:10px;text-align:right;direction:rtl;">
t 			<h2 align="center">تنظیم زبان مرورگر</h2>
t 			<p><font size="2">شما میتوانید از این اطلاعات 
t برای ساخت نرم افزار های <b>چند زبانه</b>
t 			 بهره ببرید.<br><br>
t 			 از مسیر های زیر میتوانید زبان مرورگر خود راتغییر دهید:
t 			 <br />
t 			 <p style="text-align:left;" class="well">
t 			 	Internet Explorer: 
t 			 	<b>Tools / Internet Options... / Languages</b><br /> Mozilla Firefox via <b>Tools /
t 			 	Options... / Content / Languages</b>.
t 			 </p>
t 			 <br />شما همچنین میتوانید با تغییر این تنظیمات در م
t رورگ خود با رفرش صفحه اطلاعات جدید را مشاهده کنید<br><br>
t 			 مرورگر شما در حال حاضر اطلاعات ز
t یر را در مورد زبان شما ارسال میکند:
t 			<div class="well">
c e زبان مرورگر:<span class="label label-success">%s<b>[%s]</b></span>
t 			</div>
t 			</font></p>
t 
t 	    </div>
t 
i pg_footer.inc
. End of script must be closed with period.
