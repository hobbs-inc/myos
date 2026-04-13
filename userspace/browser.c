<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Web Browser</title>
    <style>
        body { font-family: Arial, sans-serif; }
        #url { width: 80%; }
        #history { margin-top: 20px; }
    </style>
</head>
<body>
    <h1>Simple Web Browser</h1>
    <input type="text" id="url" placeholder="Enter URL" />
    <button onclick="navigate()">Go</button>
    <div id="content"></div>
    <div id="history"></div>

    <script>
        let history = [];
        let historyIndex = -1;

        function navigate() {
            const url = document.getElementById('url').value;
            fetch(url)
                .then(response => response.text())
                .then(data => {
                    document.getElementById('content').innerHTML = data;
                    addToHistory(url);
                })
                .catch(error => {
                    document.getElementById('content').innerHTML = '<p>Error loading page.</p>';
                });
        }

        function addToHistory(url) {
            history.push(url);
            historyIndex = history.length - 1;
            updateHistoryDisplay();
        }

        function updateHistoryDisplay() {
            const historyDiv = document.getElementById('history');
            historyDiv.innerHTML = '<h2>History</h2>' + history.map((url, index) => `<div><a href="#" onclick="loadHistory(${index})">${url}</a></div>`).join('');
        }

        function loadHistory(index) {
            historyIndex = index;
            document.getElementById('url').value = history[index];
            navigate();
        }
    </script>
</body>
</html>