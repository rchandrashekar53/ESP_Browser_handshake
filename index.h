const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
   <head>
      <title>Browser Status</title>
   </head>
   <body>
      <script>
         setInterval(function() {
           // Call a function repetatively with 1 Second interval

           sendBrowserStatus();
           
         }, 1000); //1000mSeconds update rate
         

         function sendBrowserStatus() {
          $.get('/status?active=online' ,function(data){
             console.log(data);
           });
         }

      </script>
   </body>
</html>
)=====";