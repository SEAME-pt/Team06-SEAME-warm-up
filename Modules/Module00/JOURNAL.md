# JOURNAL (jmoreira)
## Module00
- Learning .md and installing Markdown extension
- Learning about qt and installing it
- Learning how to make proper tests
### GitHub
- Research about mono repos and git submodules
- Setting up github projects and team
- Learning how to manage git pull request and git branch rules
- Experimenting with GitHub Actions
- Linked Project Issues with pull request to be close on approval
- Research GitHub Labeling good practices
- Link Action to Issue
### ex02
- Github action with GTest
- Using CMake for the first time
- Remembering basic C++ like syntax and use of references, lvalues, rvalues
### ex03
- Remembering C++ classes
- Github action for compile check
- Replacing \n with std::endl, avoiding buffer not to flush. std::flush after \n is also an option
- Creating try and catch blocks to do a better job error handling and also makes life easier when using GTest
### Thoughts
- Realizing one advantage of submodules: since filesystem changed in main branch, I will have to take extra steps to ensure the GitHub Action I setup will function
- There might be a need for new GitHub Label for Issues that are tasks and research
- Need to free myself from old 42 rules like using C++98 only
### Todo
- Module01
- Gherkin and Cucumber research and implementation
- Working with Qt
### Difficulties
- When I started coding ex03 I did not manage exceptions the right way and the way the methods are built (very dependent on user input), isn't the best for testing, but still possible with mock user inputs. Think about testing before coding will be a priority from now on.
- Tried creating a friend class for testing in ex03 but still couldn't access private stuff. Will move on to m01 without implementing the test because of the time I've already spent on this. Might be CMake issue with linking or compiler issue...



