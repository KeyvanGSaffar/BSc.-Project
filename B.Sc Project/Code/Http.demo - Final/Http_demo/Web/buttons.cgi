t <!DOCTYPE html>
t <html lang="en">
t <head>
t 	<meta charset="UTF-8">
t 	<title>وضعيت سوئيچ ها</title>
t 	<link rel="stylesheet" type="text/css" href="bootstrap.min.css" />
t <script language=JavaScript type="text/javascript" src="xml_http.js"></script>
t <script language=JavaScript type="text/javascript">
# Define URL and refresh timeout
t var formUpdate = new periodicObj("buttons.cgx", 300);
t function periodicUpdate() {
t  if(document.getElementById("refreshChkBox").checked == true) {
t   updateMultiple(formUpdate);
t   periodicFormTime = setTimeout("periodicUpdate()", formUpdate.period); 
t  }
t  else
t   clearTimeout(periodicFormTime);
t }
t </script></head>
i header.inc
t 	          <li><a href="index.htm">صفحه اصلي</a></li>
t 	          <li><a href="leds.cgi">مديريت LED</li>
t 	          <li><a href="network.cgi">تنظميات شبکه</a></li>
t 	          <li><a href="system.cgi">رمز عبور</a></li>
t 	          <li><a href="tcp.cgi">وضعيت پورتها</a></li>
t 	          <li><a href="language.cgi">زبان</a></li>
t 	          <li class="active">وضعيت سوئيچ ها	</li>      
t 	          <li><a href="lcd.cgi">نمايش روي LCD</a></li>
t 	          <li><a href="temp.cgi">مشاهده دما</a></li>              
t 
t 	        </ul>
t 	      </div><!--/.well -->
t 	    </div><!--/span-->
t 	    <div class="col-md-9 pull-left well" style="margin-top:10px;text-align:right;direction:rtl;">
t 			 <h3 align="center"><br>وضعيت سوئيچ ها</h3>
t 			 <p><font size="2">در اين صفحه کاربر ميتواند وضعيت کليدهاي روي بو
t رد را به صورت زنده 
t دريافت کند اين کار بدون لود مجدد صفحه و از طريق تکنولوژي
t <b>xml</b>در اينجا براي کار
t بر مهيا شده است.که استفاده از اين تکنولوژي
t سبب به روز رساني نرم و بدون
t پرش را نتيجه ميدهد.<br><br>
t 			  براي مشاهده تغيير کافيست دکمه اي را روي برد فشار دهيد</font></p>
t 			 
t 			 <form action="buttons.cgi" method="post" id="form1" name="form1" class="well">
t 			  <span class="label label-success">دکمه ها [7..0]:</span>
t 			  <div class="btn-group pull-left">
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button7">7</span>
t 			   <span align="center"class="btn btn-info"><input type="checkbox" disabled id="button6">6</span>
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button5">5</span>
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button4">4</span>
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button3">3</span>
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button2">2</span>
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button1">1</span>
t 			   <span align="center" class="btn btn-info"><input type="checkbox" disabled id="button0">0</span>
t 			  </div>
t 			<br/><br/>
t 			  <div class="" style="text-align:center;">
t <input class="btn btn-primary" type="button" id="refreshBtn" value="Refresh" onclick="updateMultiple(formUpdate)">
t 			  Periodic:<input type="checkbox" id="refreshChkBox" onclick="periodicUpdate()"></div>
t 			</form>
t 
i footer.inc
. End of script must be closed with period.
