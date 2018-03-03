import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListSubheader } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Button from 'material-ui/Button';
import RequestMessage from '../requestMessage';

const styles = theme => ({
  sendRequestButton: {
    justifyContent: 'flex-end',
  },
  friendRequestCard: {
    backgroundColor: theme.palette.primary.main,
    margin: 0,
  },
});

class FriendsConrolView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this._state = {
      friendRequestAddress: "",
      friendRequestMessage: "",
    }

    this.handleFriendRequestAddressChanged = this.handleFriendRequestAddressChanged.bind(this);
    this.handleFriendRequestMessageChanged = this.handleFriendRequestMessageChanged.bind(this);

    this.handleSendFriendRequest = this.handleSendFriendRequest.bind(this);

    this.handleAllowFriendRequest = this.handleAllowFriendRequest.bind(this);
    this.handleDenyFriendRequest = this.handleDenyFriendRequest.bind(this);
  }

  handleFriendRequestAddressChanged = function(event) {
    var value = event.target.value;
    this._state.friendRequestAddress = value;
  }

  handleFriendRequestMessageChanged = function(event) {
    var value = event.target.value;
    this._state.friendRequestMessage = value;
  }

  handleSendFriendRequest = function() {
    this.props.callbacks.sendFriendRequestCallback({
      toxAddress: this._state.friendRequestAddress,
      message: this._state.friendRequestMessage,
    })
  }

  handleAllowFriendRequest = function(uid) {
    this.props.callbacks.allowFriendRequestCallback(uid);
  }

  handleDenyFriendRequest = function(uid) {
    this.props.callbacks.denyFriendRequestCallback(uid);
  }

  render() {
    return (
      <Grid item>
        <List>
          {
            this.props.requests.map((request) => (
              <RequestMessage
                key={ request.uid }
                uid={ request.uid }
                nickname={ request.toxAddress }
                message={ request.message }
                time={ request.time }
                allowRequestCallback={ this.handleAllowFriendRequest }
                denyRequestCallback={ this.handleDenyFriendRequest }
              />
            ))
          }
          <ListSubheader disableSticky>
            Add friend
          </ListSubheader>
          <ListItem>
            <TextField
              onChange={ this.handleFriendRequestAddressChanged }
              helperText="Tox ID or name@example.com"
              fullWidth
            />
          </ListItem>
          <ListItem>
            <TextField
              onChange={ this.handleFriendRequestMessageChanged }
              placeholder="Hello, please add me to your friends"
              helperText="Message"
              multiline 
              fullWidth 
              rows="10"
            />
          </ListItem>
          <ListItem className={ this.classes.sendRequestButton }>
            <Button 
              color="secondary"
              onClick={ this.handleSendFriendRequest }
            >
              Send request
            </Button>
          </ListItem>
        </List>
      </Grid>
    );
  }
}

FriendsConrolView.propTypes = {
  classes: PropTypes.object.isRequired,
  requests: PropTypes.array,
  callbacks: PropTypes.shape({
    sendFriendRequestCallback: PropTypes.func,
    allowFriendRequestCallback: PropTypes.func,
    denyFriendRequestCallback: PropTypes.func,
  }),
};

FriendsConrolView.defaultProps = {
  requests: [],
  callbacks: {
    sendFriendRequestCallback: ((request) => {}),
    allowFriendRequestCallback: ((uid) => {}),
    denyFriendRequestCallback: ((uid) => {}),
  },
}

export default withStyles(styles)(FriendsConrolView);
