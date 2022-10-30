function test()
{
    bash_put=$(echo $1 | bash)
    mine_put=$(echo $1 | ./minishell)


    if [ ["$bash_put"] == ["$mine_put"] ]
    then 
    {
        echo $bash_put
        echo $mine_put
        echo "You're Good"
    }
    fi
    {
        echo $bash_put
        echo '\n'
        echo $mine_put
        echo '\n'
        echo "You're Screwed"
    }
}

test "ls"