t <!DOCTYPE html>
t <html lang="en">
t <head>
t <meta charset="UTF-8">
t <title>نمایش بر روی LCD</title>
t <link rel="stylesheet" type="text/css" href="bootstrap.min.css" />
i header.inc
t 	  <li><a href="index.htm">صفحه اصلی</a></li>
t 	  <li><a href="leds.cgi">مدیریت LED</li>
t 	  <li><a href="network.cgi">تنظمیات شبکه</a></li>
t 	  <li><a href="system.cgi">رمز عبور</a></li>
t 	  <li><a href="tcp.cgi">وضعیت پورتها</a></li>
t 	  <li><a href="language.cgi">زبان</a></li>
t 	  <li><a href="buttons.cgi">وضعیت سوئیچ ها	</a></li>      
t 	  <li class="active">نمایش روی LCD</li>
t 	  <li><a href="temp.cgi">مشاهده دما</a></li>              
t 
t 	</ul>
t   </div><!--/.well -->
t </div><!--/span-->
t <div class="col-md-9 pull-left well" style="margin-top:10px;text-align:right;direction:rtl;">
t 	<h3>نمایش بر روی LCD</h3>
t 	<br/>
t 	<div class="well">
t 	متنی که شما بر در باکس زیر بنویسید بر روی 
t 	LCD نمایش داده خواهد شد
t 	<form action="lcd.cgi" method="post" name="cgi" style="text-align:center;">	
t 		<textarea name="text" class="alert alert-info" style="height:55px;width:180px;line-height30px;">
c l %s
t 		</textarea>
t 		<br />
t 		<input type="submit" value="Write on LCD" class="btn btn-info" />		
t 	</form>
t 	</div>
t </div>
i footer.inc
. End of script must be closed with period.
