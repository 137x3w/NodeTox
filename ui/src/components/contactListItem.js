import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemAvatar, ListItemText } from 'material-ui/List';
import Avatar from 'material-ui/Avatar';
import Typography from 'material-ui/Typography';
import IconButton from 'material-ui/IconButton';
import DeleteIcon from 'material-ui-icons/Delete';
import Badge from 'material-ui/Badge';
import classnames from 'classnames';

const styles = theme => ({
  contactListItem: {
    overflow: 'auto',
    // height: '94px',
    paddingRight: '32px',
    background: theme.palette.primary.main,
  },
  avatarContainer: {
    position: 'relative',
    '&:after': {
      borderRadius: '50%',
      content: "''",
      width: '10px',
      height: '10px',
      position: 'absolute',
      bottom: '0',
      right: '0',
    },
  },
  offlineConnectionStatus: {
    '&:after': {
      backgroundColor: "transparent",
    }
  },
  noneConnectionStatus: {
    '&:after': {
      backgroundColor: "#76FF03",
    }
  },
  awayConnectionStatus: {
    '&:after': {
      backgroundColor: "#FFEA00",
    }
  },
  busyConnectionStatus: {
    '&:after': {
      backgroundColor: "#FF3D00",
    }
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

  }
});

class ContactListItem extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
    this.classes = props.classes;
    this.listItemClicked = this.listItemClicked.bind(this);
  }

  listItemClicked() {
    this.safeProps.listItemClickCallback(this.safeProps.uid);
  }

  handleProps(props) {
    var result = {
      nickname: props.nickname || "User",
      statusMessage: props.statusMessage || "Status",
      avatarSrc: props.avatarSrc || "",
      connectionStatus: props.connectionStatus || "offline",
      unreadMessagesCount: props.unreadMessagesCount || 0,
      listItemClickCallback: props.listItemClickCallback || (() => {}),
      uid: props.uid || "0",
    }
    return result;
  }
  
  render() {
    this.safeProps = this.handleProps(this.props);
    return (    
      <ListItem button divider className={this.classes.contactListItem} onClick={ this.listItemClicked }>
        <div className={
          classnames(this.classes.avatarContainer, this.classes[this.safeProps.connectionStatus + 'ConnectionStatus'])
        }>
          <ListItemAvatar>
            <Avatar className={ this.classes.contactListItemAvatar } alt="User avatar" src={ this.safeProps.avatarSrc }>
              { this.safeProps.avatarSrc ? null : this.safeProps.nickname.charAt(0) }
            </Avatar>
          </ListItemAvatar>
        </div>
        <ListItemText
          primary={
              <Typography noWrap gutterBottom className={ this.classes.contactListItemNickname }>
                {this.safeProps.nickname}
              </Typography>
          }
          secondary={
            <Typography variant="caption" noWrap gutterBottom className={ this.classes.contactListItemStatusMessage }>
              {this.safeProps.statusMessage}
            </Typography>         
          }
        />
        {
          this.safeProps.unreadMessagesCount > 0 && (<Badge children color="primary" badgeContent={ "+" + this.safeProps.unreadMessagesCount } className={ this.classes.contactListItemBadge }> </Badge>)
        }
      </ListItem>
    );
  }
}

ContactListItem.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ContactListItem);
