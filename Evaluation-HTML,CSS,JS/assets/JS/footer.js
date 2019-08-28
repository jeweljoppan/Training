// ===========  GLOBAL ============ //

// ===========  VALIDATE FUNCTION  ============ //
function validate() {
	var name = $("#name").val();
	var message = $("#comment").val();
	$("#comment")[0].style.border = "1px solid #a8a8a8";
	$("#malert")[0].style.display = "none";
	$("#name")[0].style.border = "1px solid #a8a8a8";
	$("#nalert")[0].style.display = "none";
	if (message == "") {
		$("#comment")[0].style.border = "2px solid red";
		document.contact.name.focus();
		$("#malert")[0].style.display = "block";
		return false;
	}

	var letter = /^[a-zA-Z_ ]+$/;
	if (!name.match(letter)) {
		$("#name")[0].style.border = "2px solid red";
		document.contact.name.focus();
		$("#nalert")[0].style.display = "block";
		return false;
	}

	return true;
}
