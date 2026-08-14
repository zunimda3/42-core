# Teaching Notes

- Learner has completed and passed the 42 Piscine.
- Use `00-libft-en.pdf` as the main instruction sheet for the learner's Libft curriculum and consult it when planning lessons, exercises, and project requirements.
- Keep lessons short, implementation-driven, and above introductory C syntax.
- Use selected GitHub repositories as exercise sources, not as behavioral specifications; if they disagree with `00-libft-en.pdf`, follow the PDF.
- Emphasize contract reading, edge-case prediction, testing, memory ownership, and verbal defense.
- All HTML lessons and reference documents must use the shared dark-mode stylesheet; do not provide a light theme, including for print.
- Initial lesson on function contracts and `strlcpy` was far above the learner's current conceptual footing. Introduce one concrete mechanism at a time through runnable C, starting with byte arrays and NUL-terminated strings; define every new term in plain language.
- Use an easy-to-read system sans-serif font for lesson prose; avoid serif body fonts.
- Every lesson should contain only one objective, the minimum information and resources needed for it, and one exercise for the learner to complete. Do not include a solved implementation of the exercise. Review the learner's attempt before advancing.
- Whenever giving the learner the next exercise, always include the complete instructions and expected behavior; do not provide only the function name.
- Always use the `session-teacher` skill when checking or working through exercises. Compile and test the actual code, then teach and quiz incrementally until the learner demonstrates understanding before marking the exercise complete.
- After an exercise is satisfactorily completed and verified, commit its implementation and learning record to Git before moving to the next exercise.
