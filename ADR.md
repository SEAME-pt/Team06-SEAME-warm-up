## 11-11
Qt installed in ndo-vale's account
### Decided on the organization of the repo
We shall have one repo per project, including the warmup
- Warmup is small enough for the different modules to not need individual issues, therefore no need to create different repos for them.
- No need to create a main repo, because we don't know yet how (or if) the different projects will be connected. It is always possible to do it later and assign existing repos as submodules.
- ADRs are different per module, because we can update each module's ADR concurrently without conflicts.
