import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemAvatar, ListItemText } from 'material-ui/List';
import Typography from 'material-ui/Typography';
import Badge from 'material-ui/Badge';
import MediaAvatar from './mediaAvatar';

const styles = theme => ({
  contactListItem: {
    overflow: 'auto',
    paddingRight: '32px',
    background: theme.palette.primary.main,
  },
  contactListItemNickname: {
    color: theme.palette.primary.contrastText,
  },
  contactListItemStatusMessage: {
    color: theme.palette.primary.contrastText,
    fontWeight: '300',
  },
});

class ContactListItem extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.listItemClicked = this.listItemClicked.bind(this);
  }

  listItemClicked() {
    this.props.clickCallback(this.props.uid);
  }
  
  render() {
    return (    
      <ListItem button divider className={this.classes.contactListItem} onClick={ this.listItemClicked }>
        <ListItemAvatar>
          <MediaAvatar
            src={ this.props.avatarSrc }
            char={ this.props.avatarSrc ? null : this.props.nickname.charAt(0) }
            connectionStatus={ this.props.connectionStatus }
            styleType="contactList"
          />
        </ListItemAvatar>
        <ListItemText
          primary={
              <Typography noWrap gutterBottom className={ this.classes.contactListItemNickname }>
                {this.props.nickname}
              </Typography>
          }
          secondary={
            <Typography variant="caption" noWrap gutterBottom className={ this.classes.contactListItemStatusMessage }>
              {this.props.statusMessage}
            </Typography>         
          }
        />
        {
          this.props.unreadMessagesCount > 0 && (
            <Badge children color="primary" badgeContent={ "+" + this.props.unreadMessagesCount }> </Badge>
          )
        }
      </ListItem>
    );
  }
}

ContactListItem.propTypes = {
  classes: PropTypes.object.isRequired,
  nickname: PropTypes.string,
  statusMessage: PropTypes.string,
  avatarSrc: PropTypes.string,
  connectionStatus: PropTypes.string,
  unreadMessagesCount: PropTypes.number,
  clickCallback: PropTypes.func,
  uid: PropTypes.string,
};

ContactListItem.defaultProps = {
  nickname: "Default nickname",
  statusMessage: "Default status message",
  avatarSrc: "",
  connectionStatus: "offline",
  unreadMessagesCount: 0,
  clickCallback: (() => {}),
  uid: "0",
}

export default withStyles(styles)(ContactListItem);
