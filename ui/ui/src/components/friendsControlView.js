import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListSubheader } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Button from 'material-ui/Button';
import RequestMessage from './requestMessage';

const styles = theme => ({
  sendRequestButton: {
    justifyContent: 'flex-end',
  },
  friendRequestCard: {
    backgroundColor: theme.palette.primary.main,
    margin: 0,
  }
});

class FriendsConrolView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {    
    return (
      <Grid item>
        <List>
          {
            this.props.requests.map((request) => (
              <RequestMessage
                key={ request.uid }
                nickname={ request.toxid }
                message={ request.message }
                time={ request.time }
              />
            ))
          }
          <ListSubheader disableSticky>
            Add friend
          </ListSubheader>
          <ListItem>
            <TextField              
              defaultValue={ this.props.statusMessage }
              helperText="Tox ID or name@example.com"
              fullWidth
            />
          </ListItem>
          <ListItem>
            <TextField
              label="Hello, please add me to your friends"
              helperText="Message"
              multiline 
              fullWidth 
              rows="10"
            />
          </ListItem>
          <ListItem className={ this.classes.sendRequestButton }>
            <Button color="secondary" >
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
};

FriendsConrolView.defaultProps = {
  requests: [],
}

export default withStyles(styles)(FriendsConrolView);
