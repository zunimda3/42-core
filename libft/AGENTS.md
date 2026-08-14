# Repository instructions

## Required Codex skills

At the beginning of the first Codex turn in this repository, before working on
an exercise, verify that each of these files exists:

- `${CODEX_HOME:-$HOME/.codex}/skills/teach/SKILL.md`
- `${CODEX_HOME:-$HOME/.codex}/skills/session-teacher/SKILL.md`
- `${CODEX_HOME:-$HOME/.codex}/skills/agent-teacher/SKILL.md`

Install only the missing skills. Use `python3` and the bundled skill installer:

```sh
installer="${CODEX_HOME:-$HOME/.codex}/skills/.system/skill-installer/scripts/install-skill-from-github.py"

test -f "${CODEX_HOME:-$HOME/.codex}/skills/teach/SKILL.md" || \
  python3 "$installer" \
    --url https://github.com/mattpocock/skills/tree/main/skills/productivity/teach

test -f "${CODEX_HOME:-$HOME/.codex}/skills/session-teacher/SKILL.md" || \
  python3 "$installer" \
    --repo apxxrv/session-teacher --path teach --name session-teacher

test -f "${CODEX_HOME:-$HOME/.codex}/skills/agent-teacher/SKILL.md" || \
  python3 "$installer" \
    --repo JackyYang258/agent-teacher --path . --name agent-teacher
```

After any installation, verify that all three `SKILL.md` files exist. If an
installation fails, tell the user which skill is unavailable before proceeding
with work that depends on it. Do not reinstall a skill whose `SKILL.md` already
exists.

## Teaching workspace

Exercises in this repository may rely on `teach`, `session-teacher`, and
`agent-teacher`. Follow a named skill's instructions whenever the user's request
triggers it.
