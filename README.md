# text-adventure-creator
Mini project to create a text based adventure game from formatted text

Build by running ```make```

After running the program, enter the name of the story to create without the txt file extension. A default test story is in the stories folder.
To run it, enter ```test``` when prompted for the name of a story

# Making a new story:
    - Insert a new txt file into the stories folder
    - In the first 3 lines, enter the name of the point system, the initial prompt, and the ending message
    - Afterwards, follow the node format below to create a new story node that is the child of the last node of lower level (look at test.txt for reference)
    - Make sure there are no new extra newlines after the last node and the story is ready!

# Node format:

```
level points
answer option
new story scenario (enter anything, but preferably null for a leaf node)
```
