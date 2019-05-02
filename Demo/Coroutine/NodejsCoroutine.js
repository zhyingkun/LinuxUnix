console.log("Start...");
function* remoteCompile() {
  console.log("In getPara Now...");
  // do something
  yield null;
  console.log("In doCompile Now...");
  // do something
  yield null;
  console.log("In uploadResult Now...");
  // do something
  return null;
}
var iter = remoteCompile();
for(;;){
  var status = iter.next();
  console.log("Check done now...");
  if(status.done){
	  break;
  }
}
console.log("End");
