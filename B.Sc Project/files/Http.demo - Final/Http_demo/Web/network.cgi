t <!DOCTYPE html>
t <html lang="en">
t <head>
t <meta charset="UTF-8">
t <title>ویرایش مشخصات شبکه</title>
i header.inc
t 	          <li ><a href="index.htm">صفحه اصلی</a></li>
t 	          <li><a href="leds.cgi">مدیریت LED</a></li>
t 	          <li class="active" >تنظمیات شبکه</li>
t 	          <li><a href="system.cgi">رمز عبور</a></li>
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
t 			 <h3>ویرایش مشخصات شبکه
t 			 </h3>
t 			 <span>
t 			 <p dir="rtl" class="well btn-warning" style="color:#000;padding:10px;font-size:10px;">
t 			 در این فرم شما قادر هستید که آدرس اختصاصی(IP)
t 			 اختصاص یافته شده به برد را تغییر دهید.این ت
t غییر ممکن است منجر به قطع ارتباط با سرور شود.
t 			 در صورت رخ دادن این واقعه ادرس جدید را در 
t 			 مرورگر وارد کنید و یا برد را ریست کنید.
t 			   
t 			   در این فرم از ارسال داده به صورت get
t 			 استفاده شده است و میتوانید نتیجه را مشاهده کنید 
t 			 </p>
t 			 <form action="network.cgi" method="get" name="cgi">
t 				 <table class="table table-hover">
t 				   	<thead>
t 					   	<tr>
t 						  	<td class="litem">
t 						          Item
t 						    </td>
t 					     	<td class="ritem">
t 					 			Setting
t 					     	</td>
t 					     <tr>
t 					 </thead>
t 					<tbody>
t 						<tr>
t 							<td>LAN IP Address</td>	
t 							<td>
c a i 	<input type=text name=ip value="%d.%d.%d.%d" size=18 maxlength=18>
t 							</td>
t 						</tr>
t 						<tr>
t 							<td>LAN Net Mask</td>	
t 							<td>
c a m 	<input type=text name=msk value="%d.%d.%d.%d" size=18 maxlength=18>
t 							</td>
t 						</tr>
t 						<tr>
t 							<td>Default Gateway</td>	
t 							<td>
c a g	<input type=text name=gw value="%d.%d.%d.%d" size=18 maxlength=18>
t 							</td>
t 						</tr>
t 						<tr>
t 							<td>Primary DNS Server</td>	
t 							<td>
c a p 	<input type=text name=pdns value="%d.%d.%d.%d" size=18 maxlength=18>
t 							</td>
t 						</tr>
t 						<tr>
t 							<td>Secondary DNS Server</td>	
t 							<td>
c a s 	<input type=text name=sdns value="%d.%d.%d.%d" size=18 maxlength=18>
t 							</td>
t 						</tr>
t 						<tr>
t 							<td>
t <input type="button" class="btn btn-success pull-left" value="تغییر" onclick="changeConfirm(this.form)" />
t 						     </td>
t 							<td>
t 						       <input type="reset" class="btn btn-danger" value="بازگردانی" />
t 						     </td>
t 						</tr>
t 					</tbody>
t 				 </table>
t 			 </form>
t 			 <br />
t 			 <br />
t 			 </span>  
t 		</div>
t     </div>
i footer.inc
.End of program