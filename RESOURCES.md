# Libft Resources

## Knowledge

- [Current 42 Libft subject mirror — 42 Cursus GitBook](https://42-cursus.gitbook.io/guide/0-rank-00/libft/subject)
  Use for: the project deliverables and function list. Confirm against the subject PDF in the student's intra when available, because mirrors can lag curriculum revisions.
- [OpenBSD manual: `strlcpy` and `strlcat`](https://man.openbsd.org/strlcpy.3)
  Primary implementation-family documentation for exact size, termination, return-value, truncation, and overlap contracts.
- [The Open Group: `<string.h>`](https://pubs.opengroup.org/onlinepubs/009696799/basedefs/string.h.html)
  Standards-oriented index for the string and raw-memory interfaces reimplemented by Libft; follow individual function links for contracts.
- [OpenBSD manual: `strlen`](https://man.openbsd.org/strlen.3)
  Use for the exact meaning of string length and the distinction between characters counted and the terminating NUL.
- [OpenBSD manual: `strncmp`](https://man.openbsd.org/strncmp.3)
  Use for bounded comparison semantics, especially unsigned-character comparison and sign-only return guarantees.
- [OpenBSD manual: `isalpha`](https://man.openbsd.org/isalpha.3)
  Use for the alphabetic-character contract, non-zero/zero return behavior, and the valid argument domain.
- [cj4ck/42-libft](https://github.com/cj4ck/42-libft/blob/master/README.md)
  Learner implementation and navigable function inventory. Use for exercises and comparison only, never as the authority on behavior.
- [MarkosComK/42-Common-Core-Guide](https://github.com/MarkosComK/42-Common-Core-Guide)
  Community roadmap for project order and broad orientation. Treat dates, scoring, and administrative details as potentially stale.

## Wisdom (Communities)

- 42 campus peers and peer evaluators
  Use for: explaining functions aloud, adversarial edge-case review, and learning campus-specific evaluation habits without exchanging submit-ready code.

## Gaps

- Add the exact current Libft subject PDF from the user's 42 intra when available; it is the controlling source.
- Add campus-approved Norm and evaluation references once the user's campus/tooling environment is known.
