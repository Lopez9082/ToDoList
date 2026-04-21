<!DOCTYPE html>
<html lang="pt-BR">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Para Você ❤️</title>

<style>
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    height: 100vh;
    font-family: 'Segoe UI', sans-serif;
    background: linear-gradient(135deg, #1e1e2f, #3a0ca3, #ff4d6d);
    display: flex;
    justify-content: center;
    align-items: center;
    overflow: hidden;
}

/* Fundo animado */
body::before {
    content: "";
    position: absolute;
    width: 200%;
    height: 200%;
    background: radial-gradient(circle, rgba(255,255,255,0.1), transparent);
    animation: moveBg 10s linear infinite;
}

@keyframes moveBg {
    0% { transform: translate(0,0); }
    100% { transform: translate(-50%, -50%); }
}

/* Card central */
.card {
    position: relative;
    padding: 40px;
    width: 320px;
    text-align: center;
    border-radius: 20px;
    backdrop-filter: blur(15px);
    background: rgba(255,255,255,0.1);
    box-shadow: 0 10px 40px rgba(0,0,0,0.4);
    color: white;
    z-index: 2;
}

/* Título */
h1 {
    font-size: 2.2em;
    margin-bottom: 15px;
    animation: fadeIn 2s ease;
}

/* Texto */
p {
    opacity: 0.85;
    margin-bottom: 25px;
}

/* Botão */
button {
    padding: 12px 20px;
    border: none;
    border-radius: 30px;
    background: linear-gradient(45deg, #ff4d6d, #ff758f);
    color: white;
    font-size: 1em;
    cursor: pointer;
    transition: 0.3s;
}

button:hover {
    transform: scale(1.1);
}

/* Mensagem escondida */
.hidden {
    margin-top: 20px;
    opacity: 0;
    transition: 1s;
}

.show {
    opacity: 1;
}

/* Corações flutuando */
.heart {
    position: absolute;
    font-size: 20px;
    animation: floatUp 6s linear infinite;
}

@keyframes floatUp {
    0% {
        transform: translateY(100vh);
        opacity: 0;
    }
    50% {
        opacity: 1;
    }
    100% {
        transform: translateY(-10vh);
        opacity: 0;
    }
}

@keyframes fadeIn {
    from {opacity: 0; transform: translateY(20px);}
    to {opacity: 1; transform: translateY(0);}
}
</style>
</head>

<body>

<div class="card">
    <h1>Te amo muitão ❤️</h1>
    <p>Isso é só uma forma simples de te lembrar o quanto você é especial pra mim.</p>

    <button onclick="mostrarMensagem()">Clique aqui 💌</button>

    <div id="mensagem" class="hidden">
        Eu te amo mais do que palavras conseguem explicar 💖
    </div>
</div>

<!-- Música Armandinho -->
<iframe width="0" height="0"
src="https://www.youtube.com/embed/0v2c7V8y6mI?autoplay=1&loop=1&playlist=0v2c7V8y6mI"
allow="autoplay">
</iframe>

<script>
function mostrarMensagem() {
    document.getElementById("mensagem").classList.add("show");
}

/* Criar corações */
function criarCoracao() {
    const heart = document.createElement("div");
    heart.classList.add("heart");
    heart.innerHTML = "❤️";
    heart.style.left = Math.random() * 100 + "vw";
    heart.style.fontSize = (Math.random() * 20 + 10) + "px";
    document.body.appendChild(heart);

    setTimeout(() => {
        heart.remove();
    }, 6000);
}

setInterval(criarCoracao, 500);
</script>

</body>
</html>
