t <!DOCTYPE html>
t <html lang="en">
t <head>
t 	<meta charset="UTF-8">
t 	<title>وضعيت پورت ها</title>
t 	<link rel="stylesheet" type="text/css" href="bootstrap.min.css" />
i header.inc
t 	          <li ><a href="index.htm">صفحه اصلي</a></li>
t 	          <li><a href="leds.cgi">مديريت LED</a></li>
t 	          <li><a href="network.cgi">تنظميات شبکه</a></li>
t 	          <li><a href="system.cgi">رمز عبور</a></li>
t 	          <li class="active">وضعيت پورتها</li>
t 	          <li><a href="language.cgi">زبان</a></li>
t 	          <li><a href="buttons.cgi">وضعيت سوئيچ ها	</a></li>      
t 	          <li><a href="lcd.cgi">نمایش روی LCD</a></li>
t 	          <li><a href="temp.cgi">مشاهده دما</a></li>              
t 	        </ul>
t 	      </div><!--/.well -->
t 	    </div><!--/span-->
t 	    <div class="col-md-9 pull-left well" style="margin-top:10px;text-align:right;direction:rtl;">
t 			<h2 align=center><br>وضعي به روز سوکت هاي TCP</h2>
t 			 <center>
t 			 <table class="table table-hover" border=0 width=600>
t 			 <font size="3">
t 			 <tr bgcolor=#aaccff>
t 			  <th width=14%>Socket</th>
t 			  <th width=20%>State</th>
t 			  <th width=20%>Rem IP</th>
t 			  <th width=16%>Rem Port</th>
t 			  <th width=16%>Loc Port</th>
t 			  <th width=14%>Timer</th>
t 			 </tr>
c c
t 			 </font>
t 			</table>
t 				 <form action=tcp.cgi method=post name=form1>
t 				  <table width=660>
t 				  <tr><td align="center">
t 				  <input type=button class="btn btn-success" value="Refresh" onclick="location='/tcp.cgi'">
t 				  </td></tr>
t 				</table>
t 				 </form>
t 			  </center>
t 
t 		</div>
t     </div>
t 
i footer.inc
. End of script must be closed with period.

