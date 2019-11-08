function manager() {
	var email = document.registration.mail.value;
	var fName = document.registration.first.value;
	var lName = document.registration.last.value;
	var gender = document.registration.gender.value;
	var area = document.registration.area.value;
	var phone = document.registration.phone.value;
	var street = document.registration.street.value;
	var city = document.registration.city.value;
	var state = document.registration.state.value;
	var pin = document.registration.pin.value;
	var respose = "";

	respose += fnameCheck(fName);
	respose += lnameCheck(lName);
	respose += areaCheck(area);
	respose += phoneCheck(phone);
	respose += cityCheck(city);
	respose += stateCheck(state);
	respose += pinCheck(pin);
	if (respose != "") {
		return false;
	}
	mailPrint(email);
	namePrint(fName, lName);
	genderPrint(gender);
	numberPrint(area, phone);
	addressPrint(street, city, state, pin);
	document.getElementById("reg").style.display = "none";
	document.getElementById("display").style.display = "block";
	return true;
}

function fnameCheck(text) {
	var letter = /^[a-zA-Z]+$/;
	if (!text.match(letter)) {
		document.getElementById("first").style.border = "1px solid red";
		document.registration.first.focus();
		document.getElementById("nalert").style.display = "block";
		return false;
	}
	document.getElementById("first").style.border = "1px solid #a8a8a8";
	document.getElementById("nalert").style.display = "none";
	return "";
}

function lnameCheck(text) {
	var letter = /^[a-zA-Z]+$/;
	if (!text.match(letter)) {
		document.getElementById("last").style.border = "1px solid red";
		document.registration.last.focus();
		document.getElementById("nalert").style.display = "block";
		return false;
	}
	document.getElementById("last").style.border = "1px solid #a8a8a8";
	document.getElementById("nalert").style.display = "none";
	return "";
}

function areaCheck(area) {
	if (area > 99 || area < 1) {
		document.getElementById("area").style.border = "1px solid red";
		document.registration.area.focus();
		document.getElementById("palert").style.display = "block";
		return false;
	}
	document.getElementById("area").style.border = "1px solid #a8a8a8";
	document.getElementById("palert").style.display = "none";
	return "";
}

function phoneCheck(phone) {
	if (phone < 100000 || phone > 999999) {
		document.getElementById("phone").style.border = "1px solid red";
		document.registration.phone.focus();
		document.getElementById("palert").style.display = "block";
		return false;
	}
	document.getElementById("phone").style.border = "1px solid #a8a8a8";
	document.getElementById("palert").style.display = "none";
	return "";
}

function cityCheck(text) {
	var letter = /^[a-zA-Z]+$/;
	if (!text.match(letter) && text) {
		document.getElementById("city").style.border = "1px solid red";
		document.registration.city.focus();
		document.getElementById("salert").style.display = "block";
		return false;
	}
	document.getElementById("city").style.border = "1px solid #a8a8a8";
	document.getElementById("salert").style.display = "none";
	return "";
}

function stateCheck(text) {
	var letter = /^[a-zA-Z]+$/;
	if (!text.match(letter) && text) {
		document.getElementById("state").style.border = "1px solid red";
		document.registration.state.focus();
		document.getElementById("salert").style.display = "block";
		return false;
	}
	document.getElementById("state").style.border = "1px solid #a8a8a8";
	document.getElementById("salert").style.display = "none";
	return "";
}

function pinCheck(pin) {
	if ((pin < 100000 || pin > 999999) && pin) {
		document.getElementById("pin").style.border = "1px solid red";
		document.registration.pin.focus();
		document.getElementById("zalert").style.display = "block";
		return false;
	}
	document.getElementById("pin").style.border = "1px solid #a8a8a8";
	document.getElementById("zalert").style.display = "none";
	return "";
}

function mailPrint(email) {
	document.getElementById("maillocation").innerHTML = email;
}
function namePrint(fName, lName) {
	document.getElementById("namelocation").innerHTML = fName + " " + lName;
}
function genderPrint(gender) {
	document.getElementById("genderlocation").innerHTML = gender;
}
function numberPrint(area, phone) {
	document.getElementById("phonelocation").innerHTML = area + " - " + phone;
}
function addressPrint(street, city, state, pin) {
	document.getElementById("addresslocation").innerHTML =
		street + ", " + city + ", " + state + ", " + pin;
}
