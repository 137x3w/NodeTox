import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemAvatar, ListItemText } from 'material-ui/List';
import Avatar from 'material-ui/Avatar';
import Typography from 'material-ui/Typography';
import IconButton from 'material-ui/IconButton';
import DeleteIcon from 'material-ui-icons/Delete';
import Badge from 'material-ui/Badge';

const styles = theme => ({
  contactListItem: {
    overflow: 'auto',
    height: '110px',
    paddingRight: '32px',
    background: theme.palette.primary.main,
  },
  contactListItemAvatar: {
    width: '50px',
    height: '50px',
    margin: '10px',
    backgroundColor: theme.palette.secondary.main,
    cursor: 'pointer',
  },
  contactListItemNickname: {
    color: theme.palette.primary.contrastText,
  },
  contactListItemStatusMessage: {
    color: theme.palette.primary.contrastText,
    fontWeight: '300',
  },
  contactListItemBadge: {
    color: theme.palette.secondary.main,
  }
});

class ContactListItem extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      nickname: props.nickname || "User",
      statusMessage: props.statusMessage || "Status",
      avatarSrc: props.avatarSrc || "",
      connectionStatus: props.connectionStatus || 0,
      unreadMessagesCount: props.unreadMessagesCount || 0,
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <ListItem button divider className={this.classes.contactListItem}>
        <ListItemAvatar>
          <Avatar className={ this.classes.contactListItemAvatar } alt="User avatar" src={ this.state.avatarSrc }>
            { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
          </Avatar>
        </ListItemAvatar>
        <ListItemText
          primary={
              <Typography noWrap gutterBottom className={ this.classes.contactListItemNickname }>
                {this.state.nickname}
              </Typography>
          }
          secondary={
            <Typography variant="caption" noWrap gutterBottom className={ this.classes.contactListItemStatusMessage }>
              {this.state.statusMessage}
            </Typography>
            
          }
        />
        {
          this.state.unreadMessagesCount > 0 && (<Badge children color="secondary" badgeContent={ this.state.unreadMessagesCount } className={ this.classes.contactListItemBadge }> </Badge>)
        }
        
      </ListItem>
    );
  }
}

ContactListItem.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ContactListItem);
