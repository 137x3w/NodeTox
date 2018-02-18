import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem } from 'material-ui/List';
import Avatar from 'material-ui/Avatar';
import Typography from 'material-ui/Typography';
import IconButton from 'material-ui/IconButton';
import DeleteIcon from 'material-ui-icons/Delete';
import Badge from 'material-ui/Badge';
import Card, { CardContent } from 'material-ui/Card';
import Grid from 'material-ui/Grid';

const styles = theme => ({
  chatMessage: {
    overflow: 'hidden',
    paddingRight: '32px',
    alignItems: ''
  },
  chatMessageAvatar: {
    width: '30px',
    height: '30px',
    margin: '10px',
    backgroundColor: theme.palette.secondary.main,
  },
  chatMessageNickname: {
    color: theme.palette.primary.contrastText,
  },
  chatMessageTime: {
    color: theme.palette.primary.contrastText,
    fontWeight: '300',
  },
  chatMessageMessage: {
    color: theme.palette.secondary.main,
  }
});

class ChatMessage extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      nickname: props.nickname || "User",
      avatarSrc: props.avatarSrc || "",
      message: props.message || "",
      time: props.time || 0,
      selfMessage: props.selfMessage || false,
      repeatedMessage: props.repeatedMessage || false,
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <ListItem className={this.classes.chatMessage}>
        <Grid item xs={0}>
          <Avatar className={ this.classes.chatMessageAvatar } alt="User avatar" src={ this.state.avatarSrc }>
            { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
          </Avatar>
        </Grid>
        <Grid item xs={10}>
          <Card>
            <CardContent>
              <Typography paragraph variant="body2">
                Method:
              </Typography>
              <Typography paragraph>
                Heat 1/2 cup of the broth in a pot until simmering, add saffron and set aside for 10
                minutes.
              </Typography>
              <Typography paragraph>
                Heat oil in a (14- to 16-inch) paella pan or a large, deep skillet over medium-high
                heat. Add chicken, shrimp and chorizo, and cook, stirring occasionally until lightly
                browned, 6 to 8 minutes. Transfer shrimp to a large plate and set aside, leaving
                chicken and chorizo in the pan. Add pimentón, bay leaves, garlic, tomatoes, onion,
                salt and pepper, and cook, stirring often until thickened and fragrant, about 10
                minutes. Add saffron broth and remaining 4 1/2 cups chicken broth; bring to a boil.
              </Typography>
              <Typography paragraph>
                Add rice and stir very gently to distribute. Top with artichokes and peppers, and
                cook without stirring, until most of the liquid is absorbed, 15 to 18 minutes.
                Reduce heat to medium-low, add reserved shrimp and mussels, tucking them down into
                the rice, and cook again without stirring, until mussels have opened and rice is
                just tender, 5 to 7 minutes more. (Discard any mussels that don’t open.)
              </Typography>
              <Typography>
                Set aside off of the heat to let rest for 10 minutes, and then serve.
              </Typography>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={1}>
          <Avatar className={ this.classes.chatMessageAvatar } alt="User avatar" src={ this.state.avatarSrc }>
            { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
          </Avatar>
        </Grid>
        {
          this.state.unreadMessagesCount > 0 && (<Badge children color="secondary" badgeContent={ this.state.unreadMessagesCount } className={ this.classes.contactListItemBadge }> </Badge>)
        }
        
      </ListItem>
    );
  }
}

ChatMessage.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ChatMessage);
