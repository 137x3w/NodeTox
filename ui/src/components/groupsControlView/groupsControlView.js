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
  }
});

class GroupsControlView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;

    this._state = {
      groupName: "",
    }

    this.handleGroupNameChanged = this.handleGroupNameChanged.bind(this);

    this.handleCreateGroup = this.handleCreateGroup.bind(this);

    this.handleAllowGroupRequest = this.handleAllowGroupRequest.bind(this);
    this.handleDenyGroupRequest = this.handleDenyGroupRequest.bind(this);
  }

  handleGroupNameChanged = function(event) {
    var value = event.target.value;
    this._state.groupName = value;
  }

  handleCreateGroup = function() {
    this.props.callbacks.createGroupCallback(this._state.groupName);
  }

  handleAllowGroupRequest = function(uid) {
    this.props.callbacks.allowGroupRequestCallback(uid);
  }

  handleDenyGroupRequest = function(uid) {
    this.props.callbacks.denyGroupRequestCallback(uid);
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
                nickname={ request.nickname }
                time={ request.time }
                allowRequestCallback={ this.handleAllowGroupRequest }
                denyRequestCallback={ this.handleDenyGroupRequest }
              />
            ))
          }
          <ListSubheader disableSticky>
            Create group
          </ListSubheader>
          <ListItem>
            <TextField
              helperText="Group name"
              fullWidth
              onChange={ this.handleGroupNameChanged }
            />
          </ListItem>
          <ListItem className={ this.classes.sendRequestButton }>
            <Button 
              color="secondary" 
              onClick={ this.handleCreateGroup }
            >
              Create group
            </Button>
          </ListItem>
        </List>
      </Grid>
    );
  }
}

GroupsControlView.propTypes = {
  classes: PropTypes.object.isRequired,
  requests: PropTypes.array,
  callbacks: PropTypes.object,
};

GroupsControlView.defaultProps = {
  requests: [],
  callbacks: {
    createGroupCallback: ((groupName) => {}),
    allowGroupRequestCallback: ((uid) => {}),
    denyGroupRequestCallback: ((uid) => {}),
  }
} 

export default withStyles(styles)(GroupsControlView);
