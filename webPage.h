const char webpage[] PROGMEM = R"rawliteral( 
<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<script
				src="https://code.jquery.com/jquery-3.5.1.min.js"
				integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0="
				crossorigin="anonymous">
	</script>
  
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">

<script src="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.5.3/js/bootstrap.min.js" integrity="sha512-8qmis31OQi6hIRgvkht0s6mCOittjMa9GMqtK9hes5iEQBQE/Ca6yGE5FsW36vyipGoWQswBj/QBm2JR086Rkw==" crossorigin="anonymous"></script>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.5.3/css/bootstrap.min.css" integrity="sha512-oc9+XSs1H243/FRN9Rw62Fn8EtxjEYWHXRvjS43YtueEewbS6ObfXcJNyohjHqVKFPoXXUxwc+q1K7Dee6vv9g==" crossorigin="anonymous" />
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Poppins:100,200,300,400,500,600,700,800,900"  crossorigin="anonymous" />
        
    </head>
    
<body>
<script type="application/javascript">
$( document ).ready(function() {
$("#sha_button_list li").click(function(){
  $(this).toggleClass( "on off" )
}); 

$(".sha_switch").click(function(){
	
	  $(this).toggleClass( "on" )

	
});

$(".swithTheme").click(function(){
  
     $("body").toggleClass( "light dark" );
  
    
    
    
});   
    
    

});

$(".sha_switch").click(function(){
  
 
  
  $(this).toggleClass( "on off" )
  
}) 
        var ws = new WebSocket("ws://%IP_OF_PAGE%/ws");

        ws.onopen = function() {
            console.log("Connected");
         };
 
         ws.onmessage = function(evt) {
            
            console.log(evt.data);
           
            document.getElementById("display").innerHTML  = evt.data;
        
        };
    

</script>    

<style type="text/css">
body
{
    background-color: #e3edf7;
    font-family: 'Poppins', sans-serif;
}

#sha_app
{
    padding: 20px 7px;
}

/** Start Section Header Bar Style **/
#sha_header_bar
{
    color: rgba(49,69,106,0.6);
}

#sha_header_bar span
{
    display: block;
}

#sha_header_bar span.sub-heading
{
    font-size: 12px;
    font-weight: 500;
    padding-top: 10px;
}

#sha_header_bar span.heading
{
    color: rgba(49,69,106,1);
    font-size: 25px;
    font-weight: 600;
    margin-top: -5px;
}
/** End Section Header Bar Style **/

/** Start Section Button List Style **/
#sha_button_list 
{
    margin-top: 10px;
}

#sha_button_list ul
{
    padding: 0;
}

#sha_button_list ul li
{
    list-style: none;
    float: left;
    width: 20%;
    text-align: center;
    padding: 10px 0;
 }

 #sha_button_list ul li:first-child
 {
    margin-left: -5px;
 }

#sha_button_list ul li span
{
    display: inline-block;
    width: 50px;
    height: 50px;
    line-height: 50px;
    border-radius: 15px;
}

#sha_button_list ul li.off span
{
    color: rgba(49,69,106,0.35);

    box-shadow: 6px 6px 10px -1px rgba(0,0,0,0.15),
                -6px -6px 10px -1px rgba(255,255,255,0.7);

 
      border: 1px solid rgba(0,0,0,0.04);
  
}

#sha_button_list ul li span{
  
  transition: all ease .5s;
}

#sha_button_list ul li.on span
{
  boder-top:3px solid rgba(0,23,0,1.5);  
  padding-top:2px;
  color: rgba(49,69,106,1.35);
background-color:rgba(49,69,106,0.0);;
    box-shadow: 3px 3px 5px -1px rgba(0,0,0,0.15), -6px -6px 10px -1px rgba(255,255,255,0.7), 0px -4px 5px rgba(0,13,0,0.3);

  
}
padding:0px 0px 0px; 
/** End Section Button List Style **/

/** Start Section Body 1 Style **/
#sha_temp_body
{
    text-align: center;
    margin-top: 30px;
}

#sha_temp_body .sha_temp
{
    position: relative;
    display: inline-block;
    width: 230px;
    height: 230px;
    border-radius: 100%;
    text-align: center;
    box-shadow: 30px 30px 30px -10px rgba(0,0,0,0.1),
                -30px -30px 30px -10px rgba(255,255,255,0.4),
                -0.5px -0.5px 0 rgba(255,255,255,1),
                0.5px 0.5px 0 rgba(0,0,0,0.02);
}

#sha_temp_body .sha_temp > span
{
    position: relative;
    display: inline-block;
    top: 50%;
    transform: translateY(-60%);
}

#sha_temp_body .sha_temp > span > span.temp-data
{
    font-size: 60px;
    font-weight: 600;
    display: block;
    color: rgba(49,69,106,1);
}

#sha_temp_body .sha_temp > span > span.temp-data sup
{
    position: absolute;
    font-size: 15px;
    font-weight: 500;
    top: 24%;
}

#sha_temp_body .sha_temp > span > span.temp-info
{
    position: absolute;
    font-size: 14px;
    font-weight: 500;
    color: rgba(49,69,106,0.6);
    white-space: nowrap;
    bottom: -10px;
    left: 50%;
    transform: translateX(-50%);
}

#sha_temp_body .sha_temp:before
{
    position: absolute;
    content: '';
    display: block;
    width: 88%;
    height: 88%;
    border-radius: inherit;
    left: 50%;
    top: 50%;
    transform: translateX(-50%) translateY(-50%);
    box-shadow: inset 4px 4px 6px -1px rgba(0,0,0,0.2),
                inset -4px -4px 6px -1px rgba(255,255,255,0.7);
}

#sha_temp_body .sha_temp:after
{
    position: absolute;
    content: '';
    display: block;
    width: 78%;
    height: 78%;
    border-radius: inherit;
    left: 50%;
    top: 50%;
    background-color: rgba(0,0,0,0.025);
    border: 1px solid rgba(0,0,0,0.01);
    transform: translateX(-50%) translateY(-50%);
    box-shadow: inset 4px 4px 6px -1px rgba(0,0,0,0.2),
                inset -4px -4px 6px -1px rgba(255,255,255,0.7);
}
/** End Section Body 1 Style **/

/** Start Section Body 2 Style **/
#sha_temp_meta
{
    margin-top: 30px;
}

#sha_temp_meta .sha_tile > div
{
    position: relative;
    border: 1px solid rgba(255,255,255,0.7);
    background-color: rgba(0,0,0,0.01);
    border-radius: 15px;  
    padding: 22px;
    box-shadow: 15px 5px 20px -10px rgba(0,0,0,0.15),
                -15px -5px 20px -10px rgba(255,255,255,0.8);
}

#sha_temp_meta .sha_tile > div span.tile_icon
{
    display: inline-block;
    width: 60px;
    height: 60px;
    text-align: center;
    line-height: 60px;
    font-size: 20px;
    border-radius: 15px;
    border: 1px solid rgba(0,0,0,0.02);
    background-color: rgba(0,0,0,0.01);
    color: rgba(49,69,106,0.6);
    box-shadow: 6px 6px 10px -1px rgba(0,0,0,0.15),
                -6px -6px 10px -1px rgba(255,255,255,0.7);
}

#sha_temp_meta .sha_tile > div span.tile_info
{
    position: absolute;
    display: inline-block;
    font-size: 16px;
    font-weight: 500;
    color: rgba(49,69,106,0.8);
    padding-left: 14px;
    margin-top: 5px;
}

#sha_temp_meta .sha_tile > div span.tile_info span
{
    display: block;
    font-weight: 400;
    color: rgba(49,69,106,0.5);
}

#sha_temp_meta .sha_tile:not(last-child)
{
    margin-bottom: 12px;
}
/** End Section Body 2 Style **/

/** Start Section Footer Style **/
#sha_footer
{
    margin-top: 15px;
    color: rgba(49,69,106,0.5);
}

#sha_footer .footer_title
{
    font-size: 15px;
    display: block;
}

#sha_footer .footer_data
{
    font-size: 18px;
    font-weight: 500;
    color: rgba(49,69,106,1);
}

#sha_footer .footer_data span
{
    color: rgba(49,69,106,0.5);
}

#sha_footer .sha_switch
{
    position: relative;
    display: inline-block;
    width: 60px;
    height: 30px;
    border-radius: 25px;
    border: 1px solid rgba(255,255,255,0.7);
    background-color: rgba(0,120,0,0.6);
    box-shadow: inset 4px 4px 8px rgba(0,0,0,0.15);
    margin-top: 2px;
  transition:all ease 0.5s;
}

#sha_footer .sha_switch:before
{
    content: '';
    position: absolute;
    width: 30px;
    height: 26px;
    background-color: #e3edf7;
    border-radius: 12px;
    right: 1px;
    top: 1px;
   transition:all ease 0.8s;
    box-shadow: 0px 2px 4px 1px rgba(0,0,0,0.15);
}
#sha_footer .sha_switch.off:before
{
    content: '';
    position: absolute;
    width: 30px;
    height: 26px;
    background-color: #e3edf7;
    border-radius: 12px;
    right: 27px;
    top: 1px;
    box-shadow: 0px 2px 4px 1px rgba(0,0,0,0.15);
}
#sha_footer .sha_switch.off
{
   background-color: #e3edf7;
  
}
#sha_footer .sha_switch.on
{}
/** End Section Footer Style **/
#sha_footer .sha_switch.off
{
   background-color: #e3edf7;
  
}
.yt {
  position: fixed;
  padding: 7px 10px 7.5px 10px;
  top: 5px;
  right: 5px;
  background: rgba(0, 0, 0, 0.7);
  border-radius: 7px;
  z-index: 99999;
}

.yt:hover {
  background: rgba(0, 0, 0, 0.4);
}

</style>

<div class="container-fluid">
  <div id="sha_app" class="row">
    <!-- Start Section Header Bar -->
    <section id="sha_header_bar" class="col-12">
      <div class="row">
        <div class="col-12">

        </div>
        <div class="col-12">
          <!--           <span class="sub-heading">Dashboard</span> -->
          <span class="heading">Kuchnia</span>
        </div>
      </div>
    </section>
    <!-- End Section Header Bar -->

    <!-- Start Section Body 1 -->
    <section id="sha_temp_body" class="col-12">
      <div class="row">
        <div class="col-12">
          <span class="sha_temp">
            <span>
              <span class="temp-data"> 16 <sup>&deg;C</sup> </span>
              <!--               <span class="temp-info">
                <i class="fa fa-snowflake-o"></i> Ogrzewanie
              </span>
            </span> -->
            </span>
        </div>
      </div>
    </section>
    <!-- End Section Body 1 -->

    <!-- Start Section Footer -->
    <section id="sha_footer" class="col-12">
      <div class="row">

        <div class="col-4">
          <div>
            <span class="footer_title text-left">
              ESP-NOW protocol
            </span>
            <span class="footer_data">
              <span class="sha_switch on"></span>
            </span>
          </div>
          <div>
            <span class="footer_title text-left">
              ESP-NOW
            </span>
            <span class="footer_data">
              <span class="sha_switch off"></span>
            </span>
          </div>
        </div>
      </div>
    </section>
    <!-- End Section Footer -->
  </div>
</div>

<p class="sha_switch">switch</p>

<div id="display">WSocket</div>
</body>
</html>


)rawliteral";