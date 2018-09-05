new function() {
	var ws = null;
	var serverUrl;
	var connectButton;
	var disconnectButton; 
	var sendButton;

	var open = function() {
		ws = new WebSocket(serverUrl.val());
	}
	
	var close = function() {
		if (ws) {
			ws.close();
		}
	}
	
	var addMessage = function(data) {
		var messages = $('#messages');
		messages.append(data);
	}
	
	function show_image(src, width, height, alt) {
		var img = document.createElement("img");
		img.src = src;
		img.width = width;
		img.height = height;
		img.alt = alt;

		// This next line will just add it to the <body> tag
		document.body.appendChild(img);
	}
		
	WebSocketClient = {
		init: function() {
			serverUrl = $('#serverUrl');
			connectButton = $('#connectButton');
			disconnectButton = $('#disconnectButton'); 
			sendButton = $('#sendButton');
			imageButton = $('#imageButton');
			
			connectButton.click(function(e) {
				ws = new WebSocket(serverUrl.val());
				ws.onmessage = function(evt) {
					if ($('#sendMessage').val() == "image") {
						show_image('data:image/png;base64, ' + evt.data, 220, 165, 'image')
						addMessage(evt.data)
					} else {
						addMessage(evt.data)
					}
				}
			});
		
			disconnectButton.click(function(e) {
				if (ws) {
					ws.close();
				}
			});
			
			sendButton.click(function(e) {
				var msg = $('#sendMessage').val();
				ws.send(msg);
			});
			
			imageButton.click(function(e) {
				show_image('https://www.google.de/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png',272,92,'Google')
			});
		}
	};
}

$(function() {
	WebSocketClient.init();
});