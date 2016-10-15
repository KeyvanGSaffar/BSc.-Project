t <!DOCTYPE html>
t <html lang="en">
t <head>
t 	<meta charset="UTF-8">
t 	<title>رمز عبور</title>
t 	<link rel="stylesheet" type="text/css" href="bootstrap.min.css" />
i header.inc
t 	          <li ><a href="index.htm">صفحه اصلی</a></li>
t 	          <li><a href="leds.cgi">مدیریت LED</a></li>
t 	          <li><a href="network.cgi">تنظمیات شبکه</a></li>
t 	          <li class="active">رمز عبور</li>
t 	          <li><a href="tcp.cgi">وضعیت پورتها</a></li>
t 	          <li><a href="language.cgi">زبان</a></li>
t 	          <li><a href="buttons.cgi">وضعیت سوئیچ ها	</a></li>              
t 	          <li><a href="lcd.cgi">نمایش روی LCD</a></li>
t 	          <li><a href="temp.cgi">مشاهده دما</a></li>              
t 
t 	        </ul>
t 	      </div><!--/.well -->
t 	    </div><!--/span-->
t 	    <div class="col-md-9 pull-left well" style="margin-top:10px;text-align:right;direction:rtl;">
t 					<h3>
t 			 ویرایش مشخصات کاربری</h3>
t 			 <span>
t 			 <p dir="rtl"  class="well btn-warning" style="color:#000;padding:10px;font-family:Tahoma;font-size:10px;">
t 			 در این صفحه 	شما قادر خواهید بود که رمز کاربر
t 			 ی مورد استفاده برای ورود به صفحه مدیریت را تغییر دهید.
t 			 </p>
t 			 <form action="index.htm" method="post" name="cgi">
t 			 	<table class="table table-hover">
t 			 		<tr>
t 			 			<td>
t 			 				شناسه کاربری:
t 			 			</td>
t 			 			<td>
c d 1		<b>%s</b>			 				
t 			 			</td>
t 			 		</tr>
t 			 		<tr>
t 			 			<td>
t 			 				رمز عبور:
t 			 			</td>
t 			 			<td>
c d 2 <td><input type=password id=pw name=pw size=10 maxlength=20 value="%s"></td></tr>
t 						</td>
t 			 		</tr>
t 			 		<tr>
t 			 			<td>
t 			 				تکرار مجدد رمز عبور:
t 			 			</td>
t 			 			<td>
c d 2 <td><input type=password id=pw2 name=pw2 size=10 maxlength=20 value="%s"></td></tr>
t 						</td>
t 			 		</tr>
t 			 	</table>
t 					<div class="btn-group" style="width:50%;text-align:center;">
t 					       <button class="btn btn-primary pull-left" onclick="changePass(this.form)" >تغییر</button>
t 					       <input type="reset" class="btn btn-warning" value="بازگردانی" />	 		
t 					 </div>
t 			 </form>
t 			 <br />
t 			 <br />
t 			 </span>  
t 		</div>
t     </div>
i footer.inc
.End Of File