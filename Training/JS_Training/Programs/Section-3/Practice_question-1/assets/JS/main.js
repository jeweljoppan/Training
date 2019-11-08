// ===========  GLOBAL ============ //

// -----------  Time ------------ //
function time() {
	var d = new Date();
	var year = d.getFullYear();
	var month = d.toLocaleString("default", { month: "long" });
	var day = d.getDate();
	var hour = d.getHours();
	var minute = d.getMinutes();
	var second = d.getSeconds();
	$("#date").get(0).innerHTML = day + " " + month + " " + year;
	$("#time").get(0).innerHTML = hour + " : " + minute + " : " + second;
}

// ===========  DOCUMENT READY ============ //
$(document).ready(function() {
	$("#start").click(function() {
		time();
		timeVar = setInterval(time, 1000);
	});
	$("#stop").click(function() {
		clearInterval(timeVar);
	});
});
