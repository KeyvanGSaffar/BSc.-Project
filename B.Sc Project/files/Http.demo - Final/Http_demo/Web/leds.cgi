t <html xmlns="http://www.w3.org/1999/xhtml">
t <head>
t <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
t <title>مدیریت LED</title>
i header.inc
t 	          <li ><a href="index.htm">صفحه اصلی</a></li>
t 	          <li class="active">مدیریت LED</li>
t 	          <li><a href="network.cgi">تنظمیات شبکه</a></li>
t 	          <li><a href="system.cgi">رمز عبور</a></li>
t 	          <li><a href="tcp.cgi">وضعیت پورتها</a></li>
t 	          <li><a href="language.cgi">زبان</a></li>
t 	          <li><a href="buttons.cgi">وضعیت سوئیچ ها	</a></li>     
t 	          <li><a href="lcd.cgi">نمایش روی LCD</a></li>
t 	          <li><a href="temp.cgi">مشاهده دما</a></li>              
t 	        </ul>
t 	      </div><!--/.well -->
t 	    </div><!--/span-->
t 	    <div class="col-md-9 pull-left well" style="margin-top:10px;text-align:right;direction:rtl;">
t 			<h3>
t 			 مدیریت LED 
t 			 </h3>
t 			 <form action="leds.cgi" method="post" name="form1">
t 			 <input type="hidden" value="led" name="pg">
t 			   	<div class="pull-left">
t 					 <select name="ctrl" onchange="submit();" class="btn btn-info">
c b c <option value="Browser" %s>مرورگر</option><option value="blinky" %s>چراغ چشمک زن</option>
t 					 </select>
t 		    	</div>
t 			     <div class="pull-left label-info" style="padding:8px;margin-left:-5px;">
t 			       کنترل LED
t 			     </div>
t 			     <br/>
t 			     <br/>
t 			     <br/>
t 			     <table class="table table-hover">
t 			     	<thead>
t 			     		وضعیت چراغ ها
t 			     	</thead>
t 			         <tbody>
t 			         <tr valign="middle">
c b 7 <td><input type=checkbox name=led7 OnClick="submit();" %s>7</td>
c b 6 <td><input type=checkbox name=led6 OnClick="submit();" %s>6</td>
c b 5 <td><input type=checkbox name=led5 OnClick="submit();" %s>5</td>
c b 4 <td><input type=checkbox name=led4 OnClick="submit();" %s>4</td>
c b 3 <td><input type=checkbox name=led3 OnClick="submit();" %s>3</td>
c b 2 <td><input type=checkbox name=led2 OnClick="submit();" %s>2</td>
c b 1 <td><input type=checkbox name=led1 OnClick="submit();" %s>1</td>
c b 0 <td><input type=checkbox name=led0 OnClick="submit();" %s>0</td>
t 			         </tr>
t 			         </tbody>
t 			 	</table>
t 			     <table class="table table-hover">
t 			     	<thead>
t 			     		خاموش/روشن کردن کلی 
t 			     	</thead>
t 			         <tbody>
t 			         <tr valign="middle">
t 				         <td>
t <input type="button" class="btn btn-primary pull-left" style="margin-left:-10px;" value="ON" onclick="AllSW(true)">
t 				         </td>
t 				         <td>
t 				 		  	<input class="btn btn-warning" type="button" style="margin-right:-10px;" value="OFF" onclick="AllSW(false)">
t 				 		 </td>
t 			         </tr>
t 			         </tbody>
t 			 	</table>
t 
t 			 	<br />
t 			     <div class="litem" style="top:-40px;position:relative;">
t 			     </div>
t 			     <div class="ritem" style="top:-40px;position:relative;height:25px;">
t 			            
t 			     </div>
t 			 	<br />
t 			 </div>
t 			 </form>
t 			 <br />
t 			 
t 			 <br />
t 
t 
t 		   </div>
t 
t 	    </div>
i footer.inc
. End of script must be closed with period.