function validation() {
	var fName = document.registration.first.value;
	var lName = document.registration.last.value;
	var area = document.registration.area.value;
	var phone = document.registration.phone.value;
	var city = document.registration.city.value;
	var state = document.registration.state.value;
	var pin = document.registration.pin.value;
	var letter = /^[a-zA-Z]+$/;

	if (!fName.match(letter)) {
		alert("Please input a valid first name.");
		document.registration.first.focus();
		return false;
	}

	if (!lName.match(letter)) {
		alert("Please input a valid last name.");
		document.registration.last.focus();
		return false;
	}

	if (area > 99 || area < 01) {
		alert("Please input a valid area code [1-99].");
		document.registration.area.focus();
		return false;
	}

	if (phone < 100000 || phone > 999999) {
		alert("Pleaser input a six digit phone number.");
		document.registration.phone.focus();
		return false;
	}

	if (!city.match(letter) && city) {
		alert("Please input a valid city.");
		document.registration.city.focus();
		return false;
	}

	if (!state.match(letter) && state) {
		alert("Please input a valid state.");
		document.registration.state.focus();
		return false;
	}
	if ((pin < 1 || pin > 99) && pin) {
		alert("Please input a valid PIN code.");
		document.registration.pin.focus();
		return false;
	}
}
function print() {
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
    
    document.write("<h1> Thank you!</h1>");
    
    doccument.write("<h3>Here is your data:</h3>");

    document.write(email + "<br/>");
}
