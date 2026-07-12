document.addEventListener("click", (event) => {
  const button = event.target.closest("button[data-answer]");
  if (!button) return;
  const quiz = button.closest(".quiz");
  quiz.querySelectorAll("button").forEach((item) => item.removeAttribute("data-state"));
  const correct = button.dataset.answer === "correct";
  button.dataset.state = correct ? "correct" : "wrong";
  quiz.querySelector(".feedback").textContent = correct
    ? button.dataset.correct
    : button.dataset.wrong;
});
